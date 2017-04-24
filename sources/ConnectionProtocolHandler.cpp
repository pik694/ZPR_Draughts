#include "ConnectionProtocolHandler.hpp"

ConnectionProtocolHandler::ConnectionProtocolHandler(connection_hdl &hdl)
{
	currentConnection_ = hdl;
	state_ = ConnectionStates::JUST_STARTED;
}

void ConnectionProtocolHandler::parseJson(std::string data)
{
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
bool ConnectionProtocolHandler::tryToAssingName(const std::string &name)
{
	throw std::runtime_error("Not implemented yet");
}