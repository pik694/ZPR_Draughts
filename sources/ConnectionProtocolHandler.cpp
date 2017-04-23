#include "ConnectionProtocolHandler.hpp"

ConnectionProtocolHandler::ConnectionProtocolHandler(RoomManager &manager_a,ClientManager clients_manager_a, connection_hdl &hdl)
{
	manager = manager_a;
	current_connection = hdl;
	state = ConnectionStates::JUST_STARTED;
}

void ConnectionProtocolHandler::ParseJson(std::string data)
{
	Json::Value action;
	/*switch(state)
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
bool ConnectionProtocolHandler::TryAssignName(std::string &name)
{
	throw std::runtime_error("Not implemented yet");
}