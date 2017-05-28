#include "Server.hpp"
#include <websocketpp/connection.hpp>

#include <websocketpp/logger/levels.hpp>
#include <websocketpp/version.hpp>
#include <websocketpp/endpoint.hpp>
typedef websocketpp::server<websocketpp::config::asio> server;
using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::mutex;
using websocketpp::connection_hdl;
using websocketpp::lib::ref;
using websocketpp::lib::thread;
using websocketpp::lib::lock_guard;
using websocketpp::lib::unique_lock;
//typedef typename websocketpp::connection::connection_type::ptr connection_ptr;
//Server::Server()
//{
//	web_socket_server.init_asio();
//}
//void Server::on_open(connection_hdl hdl)
//{
//	client_list.push_back(new ConnectionProtocolHandler(manager,my_client_manager,hdl));
//
//}
//void Server::on_close(connection_hdl hdl)
//{
//
//}
//void Server::run()
//{
//	//.listen(8080);
//	//web_socket_server.start_accept();
//}
mutex Server::m_action_lock;
condition_variable Server::m_action_cond;
std::queue<Action> Server::m_actions;
typedef websocketpp::server<websocketpp::config::asio> server;
typedef server::message_ptr message_ptr;
Server::Server()  {
	//throw std::runtime_error("Not implemented yet");
	//boost::asio::io_service io_service;
	//boost::asio::signal_set _signals(io_service,SIGINT);
	//signals_.add(SIGINT);
	//io_service.run();
	//std::cout<<"wtf just happened"<<std::endl;
}
Server::~Server() {
	stopServer();
}

void Server::stopServer() {
	std::cout<<"what is going on ?"<<std::endl;
	webSocketServer_.stop_listening();
	exit(0);
}

void Server::onOpen(connection_hdl hdl) {
	std::cout<<"Connection opened"<<std::endl;
	{
            lock_guard<mutex> guard(m_action_lock);
            //std::cout << "on_open" << std::endl;
            m_actions.push(Action(SUBSCRIBE,hdl));
    }
    m_action_cond.notify_one();

	server::connection_ptr con = webSocketServer_.get_con_from_hdl(hdl);
	ConnectionProtocolHandler *myHandler = new ConnectionProtocolHandler(hdl);
	con->set_message_handler(bind(&ConnectionProtocolHandler::onMessage,myHandler,::_1,::_2));
	
	//con->set_message_handler(bind(&ConnectionProtocolHandler::))
	//std::cout<<"total connections: "<<connections_.size()<<std::endl;
}
void Server::onClose(connection_hdl hdl) {
	std::cout<<"Connection closed"<<std::endl;
	 {
            lock_guard<mutex> guard(m_action_lock);
            //std::cout << "on_close" << std::endl;
            m_actions.push(Action(UNSUBSCRIBE,hdl));
     }
     m_action_cond.notify_one();
	//std::cout<<"connection closed"<<std::endl;
	
	
}
void Server::onMessage(websocketpp::connection_hdl hdl, message_ptr msg) {

}
void Server::run(int port) {
	webSocketServer_.set_access_channels(websocketpp::log::alevel::all);
	webSocketServer_.clear_access_channels(websocketpp::log::alevel::all);
	webSocketServer_.init_asio();
	webSocketServer_.set_open_handler(bind(&Server::onOpen,this,::_1));
	webSocketServer_.set_close_handler(bind(&Server::onClose,this,::_1));
	webSocketServer_.set_message_handler(bind(&Server::onMessage,this,::_1,::_2));
	webSocketServer_.listen(port);
	webSocketServer_.start_accept();

	thread t(bind(&Server::processMessages,this));

	
	webSocketServer_.run();

	t.join();
}

void Server::processMessages() {
	while(1) {
		unique_lock<mutex> lock(m_action_lock);

		while(m_actions.empty()) {
			m_action_cond.wait(lock);
		}

		Action a = m_actions.front();
		m_actions.pop();

		lock.unlock();

		if (a.type == SUBSCRIBE) {
			lock_guard<mutex> guard(m_connection_lock);
			
			m_connections.insert(a.hdl);
		} else if (a.type == UNSUBSCRIBE) {
			lock_guard<mutex> guard(m_connection_lock);
			m_connections.erase(a.hdl);
		} else if (a.type == MESSAGE) {
			lock_guard<mutex> guard(m_connection_lock);
			std::cout<<"sending a message"<<std::endl;
			con_list::iterator it;
			for (it = m_connections.begin(); it != m_connections.end(); ++it) {
				webSocketServer_.send(*it,a.msg);
			}
		}
		std::cout<<"total connections: "<<m_connections.size()<<std::endl;
	}
}