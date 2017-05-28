#include "ConnectionProtocolHandler.hpp"
using websocketpp::connection_hdl;


ConnectionProtocolHandler::ConnectionProtocolHandler(connection_hdl &con,std::queue<Action> m_actions) {
	//throw std::runtime_error("Not implemented yet"); 
	currentConnection_ = con;
	actions_ = m_actions;
	state_ = ConnectionStates::JUST_STARTED;
}

void ConnectionProtocolHandler::parseJson(std::string data)
{
	throw std::runtime_error("Not implemented yet");
	Json::Value action;
	/*switch(state_)
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
	}*/
	
}
void ConnectionProtocolHandler::onMessage(websocketpp::connection_hdl hdl, message_ptr msg) {
	std::cout<<"Message: ";
	std::cout<<msg->get_payload()<<std::endl;
}

bool ConnectionProtocolHandler::tryToAssingName(const std::string &name)
{
	throw std::runtime_error("Not implemented yet");
}
