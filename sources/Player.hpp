#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

//#include <websocketpp/connection.hpp>

#include <thread>
#include <string>

using websocketpp::connection_hdl;


class Player
{
public:
	Player();
	void setNickName(std::string nick_a);
	void setRoom(int roomID);
	std::string getName();


private:
	static int clientIds_;
	std::string nickname_;
	int roomID_;
	int clientID_;
};
#endif // CLIENT_HPP