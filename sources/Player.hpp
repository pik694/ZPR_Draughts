#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
//#include <websocketpp/connection.hpp>
#include <thread>
#include <string>
#include "RoomManager.hpp"
using websocketpp::connection_hdl;
class RoomManager;
class Player
{
public:
	Player();
	void SetNickName(std::string nick_a);
	void SetRoom(int room_id_a);
	std::string GetName();
	bool operator==(const Player &arg);
private:
	static int client_ids;
	std::string nickname;
	int room_id;
	int client_id;
};
#endif // CLIENT_HPP