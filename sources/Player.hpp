#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

//#include <websocketpp/connection.hpp>

#include <thread>
#include <string>

class Room;

using websocketpp::connection_hdl;

class ConnectionProtocolHandler;

class Player
{
	using room_ptr = std::shared_ptr<Room>;

public:

	Player();
	Player(std::string nick, ConnectionProtocolHandler* hdl);

	void setNickName(std::string nick_a);
	void setRoom(int roomID);
	void setRoom(room_ptr room);
    int getRoomID();
	room_ptr getRoom();
	std::string getName();

	ConnectionProtocolHandler* getConnectionProtocolHandler();

	~Player();

private:
	static int clientIds_;
	std::string nickname_;
	room_ptr room_;
	const int clientID_;
	ConnectionProtocolHandler* connectionProtocolHandler_;
};
#endif // CLIENT_HPP