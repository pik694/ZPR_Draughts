#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

//#include <websocketpp/connection.hpp>

#include <thread>
#include <string>

#include "ConnectionProtocolHandler.hpp"

using websocketpp::connection_hdl;

class Player
{
public:

	Player();
	Player(std::string nick, ConnectionProtocolHandler* hdl);

	void setNickName(std::string nick_a);
	void setRoom(int roomID);
	std::string getName();

	ConnectionProtocolHandler* getConnectionProtocolHandler();

private:
	static int clientIds_;
	std::string nickname_;
	int roomID_;
	int clientID_;
	ConnectionProtocolHandler* connectionProtocolHandler_;
};
#endif // CLIENT_HPP