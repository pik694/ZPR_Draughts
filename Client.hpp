#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
//#include <websocketpp/connection.hpp>
#include <thread>
#include "RoomManager.hpp"
using websocketpp::connection_hdl;
class RoomManager;
enum ClientStatus {NICK_REQUEST, ROOM_REQUEST, WAITING_FOR_START, GAME_IN_PROGRESS, GAME_ENDED};
class Client
{
public:
	Client(RoomManager *manager_a,connection_hdl &client_connection_a);

private:
	void ClientTalker(connection_hdl hdl,websocketpp::server<websocketpp::config::asio>::message_ptr msg);
	//ClientStatus 
	connection_hdl client_connection;
	RoomManager *manager;
};
#endif // CLIENT_HPP