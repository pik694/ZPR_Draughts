#ifndef ZPR_DRAUGHTS_CONNECTION_HPP
#define ZPR_DRAUGHTS_CONNECTION_HPP

/*!
 * @file
 * @brief Class representing single connection handler, there is one for every client
 */ 


#include <jsoncpp/json/json.h>
#include <string>
#include <sstream>


#include "Action.hpp"
#include "MessageDispatcher.hpp"

class Signal;
class Server;
class RoomManager;
class PlayerManger;
class SignalFactory;
class BoardSignal;
class NickRequestSignal;


// accepts data in JSON format, parses them and decides what to do

/*
Typical scenario:
1.Connection opened, server creates ConnectionProtocolHandler
2.Player sends nickname_ request in json
JSON
{
	"action" : "NickRequestSignal",
	"value" : "[name send by client]"
}
3. Server accepts or if nick already taken declines
4. Player requests available rooms
JSON
{
    "action" : "RoomsRequestSignal",
}
5. Player request access to room
JSON
{
	"action" : "EnterRoomSignal",
	"requested_room" : "[number send by client]"
}
5. Player can now start the game, one of them sends a message
JSON 
{
	"action" : "NewGameSignal"
}
6. Game begins, clients send their request movements
JSON
{
	"action" : "MoveSignal",
	"value" : "[list of movements]"
}

*/
using websocketpp::connection_hdl;
using websocketpp::lib::mutex;
using websocketpp::lib::condition_variable;
typedef websocketpp::server<websocketpp::config::asio> server;
typedef server::message_ptr message_ptr;
enum ConnectionStates {
    JUST_STARTED, NICK_SET, ROOM_ASSIGNED, PLAYER_READY, GAME_IN_PROGRESS
};
using websocketpp::connection_hdl;
typedef websocketpp::server<websocketpp::config::asio> server;



/*!
 * @brief Class representing single connection handler, there is one for every client
 */
class ConnectionProtocolHandler {
public:
    
    ConnectionProtocolHandler(connection_hdl &con);

    /*!
     * Callback that gets called when
     * @param hdl Connection hdl
     * @param msg message sent by client
     */
    void onMessage(websocketpp::connection_hdl hdl, message_ptr msg);

    /*!
     * Returns connection handle
     * @return connection handle
     */
    connection_hdl getConnectionHdl();
private:
    void invalidRequest();

    bool tryToAssingName(const std::string &name);

    

    void parseJson(std::string data);

    connection_hdl currentConnection_;
    std::queue<Action> actions_;
    ConnectionStates state_;
    MessageDispatcher dispatcher_;
    //Player player_;
};

#endif