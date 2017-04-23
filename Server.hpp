#ifndef SERVER_HPP
#define SERVER_HPP
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
//#include <websocketpp/connection.hpp>
#include <list>
#include "ConnectionProtocolHandler.hpp"
#include "RoomManager.hpp"
using websocketpp::connection_hdl;
class Server
{
public:

	Server();
	void on_open(connection_hdl hdl);
	void on_close(connection_hdl hdl);
	void run();

private:
	websocketpp::server <websocketpp::config::asio> web_socket_server;
	std::list<ConnectionProtocolHandler*> client_list;
	RoomManager manager;
};
#endif //SERVER_HPP