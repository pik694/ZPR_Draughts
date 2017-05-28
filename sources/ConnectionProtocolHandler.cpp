#include "ConnectionProtocolHandler.hpp"
#include <stdio.h>
using websocketpp::connection_hdl;
using websocketpp::lib::thread;
using websocketpp::lib::lock_guard;
using websocketpp::lib::unique_lock;

ConnectionProtocolHandler::ConnectionProtocolHandler(connection_hdl &con) {
	//throw std::runtime_error("Not implemented yet"); 
	currentConnection_ = con;
	state_ = ConnectionStates::JUST_STARTED;
}

void ConnectionProtocolHandler::parseJson(std::string data)
{
	//throw std::runtime_error("Not implemented yet");
	Json::Value root;
	std::stringstream myData(data);
	std::stringstream typeStream;
	myData >> root;
	std::string myType = root.get("type","nothing").asString();
	
	Signal *currentSignal = SignalFactory::createInstance(myType);
	if(currentSignal == nullptr) {
		//invalidRequest();
		std::cout<<"not found sorry"<<std::endl;
		return;
	}
	currentSignal->acceptDispatcher(dispatcher_);

	
}

void ConnectionProtocolHandler::invalidRequest() {
	Json::Value jsonMessage;
	jsonMessage["type"] = "invalidRequest";
	std::stringstream myStream;
	myStream << jsonMessage;
	message_ptr msg;
	msg->set_payload(jsonMessage.asString());
	{
		lock_guard<mutex> guard(Server::m_action_lock);
		Server::m_actions.push(Action(MESSAGE,currentConnection_,msg));
	}
	Server::m_action_cond.notify_one();
}

void ConnectionProtocolHandler::onMessage(websocketpp::connection_hdl hdl, message_ptr msg) {
	std::cout<<"Message: ";
	std::cout<<msg->get_payload()<<std::endl;
	parseJson(msg->get_payload());
	{
		lock_guard<mutex> guard(Server::m_action_lock);
		Server::m_actions.push(Action(MESSAGE,hdl,msg));
	}
	Server::m_action_cond.notify_one();

}

bool ConnectionProtocolHandler::tryToAssingName(const std::string &name)
{
	throw std::runtime_error("Not implemented yet");
}
