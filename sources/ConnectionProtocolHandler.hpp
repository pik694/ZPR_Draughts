#ifndef ZPR_DRAUGHTS_CONNECTION_HPP
#define ZPR_DRAUGHTS_CONNECTION_HPP
#include <jsoncpp/json/json.h>
#include <string>
#include <sstream>
#include "Server.hpp"
#include "RoomManager.hpp"
#include "Player.hpp"
#include "ClientManager.hpp"
#include "Action.hpp"
#include "MessageDispatcher.hpp"
#include "Signals/Signal.hpp"
#include "Signals/NickRequestSignal.hpp"
#include "Signals/BoardSignal.hpp"
#include "Signals/SignalFactory.hpp"
// accepts data in JSON format, parses them and decides what to do

/*
Typical scenario:
1.Connection opened, server creates ConnectionProtocolHandler
2.Player sends nickname_ request in json
JSON
{
	"action" : "nick_request",
	"requested_name" : "[name send by client]"
}
3. Server accepts or if nick already taken declines
4. Player request access to room
JSON
{
	"action" : "room_request",
	"requested_room" : "[number send by client]"
}
5. Server now waits for players to be ready, they must send
JSON 
{
	"action" : "ready_to_play"
}
6. Game begins, clients send their request movements
JSON
{
	"action" : "move_pawn",
	"pos_x" : "[NUMBER]",
	"pos_y" : "[NUMBER]",
	"requested_pos_x" : "[NUMBER]",
	"request_pos_y" : "[NUMBER]"
}
7. Player may surrender by sending:
JSON
{
	"action" : "surrender"
}
8. After game ended players go back to [5]
*/
using websocketpp::connection_hdl;
using websocketpp::lib::mutex;
using websocketpp::lib::condition_variable;
typedef websocketpp::server<websocketpp::config::asio> server;
typedef server::message_ptr message_ptr;
enum ConnectionStates {JUST_STARTED, NICK_SET, ROOM_ASSIGNED, PLAYER_READY, GAME_IN_PROGRESS };
using websocketpp::connection_hdl;
typedef websocketpp::server<websocketpp::config::asio> server;
class ConnectionProtocolHandler
{
public:
	// there is going to be an event handler on_message here
	ConnectionProtocolHandler(connection_hdl &con);

	void onMessage(websocketpp::connection_hdl hdl, message_ptr msg);
	void parseJson(std::string data);
private:
	void invalidRequest();
	bool tryToAssingName(const std::string &name);
	connection_hdl currentConnection_;
	std::queue<Action> actions_;
	ConnectionStates state_;
	MessageDispatcher dispatcher_;
	//Player player_;
};

#endif