#include "ConnectionProtocolHandler.hpp"
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
	myData >> root;
	std::cout<<"getting type of it: "<<root["type"]<<std::endl;
	//std::string mytype << root["type"];
	switch(state_)
	{
		case ConnectionStates::JUST_STARTED:

		break;
		case ConnectionStates::NICK_SET:
		break;
		case ConnectionStates::ROOM_ASSIGNED:
		break;
		case ConnectionStates::PLAYER_READY:
		break;
		case ConnectionStates::GAME_IN_PROGRESS:
		break;
	}

	
}

void ConnectionProtocolHandler::invalidRequest() {
	Json::Value jsonMessage;
	jsonMessage["type"] = "invalidRequest";
	std::stringstream myStream;
	myStream << jsonMessage;
	message_ptr msg;
	msg->set_payload(myStream.str());
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
