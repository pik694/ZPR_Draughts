#ifndef SERVER_HPP
#define SERVER_HPP
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <websocketpp/connection.hpp>
#include <boost/asio/signal_set.hpp>
#include "Signals/Signal.hpp"
#include "Action.hpp"
#include <list>
#include <map>
#include <set>

class ConnectionProtocolHandler;
class Player;

using websocketpp::connection_hdl;
using websocketpp::lib::mutex;
using websocketpp::lib::condition_variable;
typedef websocketpp::server<websocketpp::config::asio> server;
typedef server::message_ptr message_ptr;
class ConnectionProtocolHandler;
//typedef websocketpp::server<websocketpp::config::asio> server_t;

class Server
{
public:

	static Server* getInstance () {
		if (instance_ == nullptr){
			instance_ = new Server();
		}

		return instance_;
	}


	~Server();
	void onOpen(connection_hdl hdl);
	void onClose(connection_hdl hdl);
	void onMessage(connection_hdl hdl, message_ptr msg);
	void run(int port);
	void processMessages();

	void putMessageInQueue(std::shared_ptr<Signal>);

	Server(const Server&) = delete;

private:

	static Server* instance_;

	Server();
	void stopServer();

	websocketpp::server <websocketpp::config::asio> webSocketServer_;
	typedef std::set<connection_hdl,std::owner_less<connection_hdl> > con_list;

    con_list m_connections;
    //std::queue<Action> m_actions;

    mutex m_connection_lock;
    mutex m_action_lock;
	condition_variable m_action_cond;
	std::queue<Action> m_actions;



};
#endif //SERVER_HPP