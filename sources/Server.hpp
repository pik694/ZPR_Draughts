#ifndef SERVER_HPP
#define SERVER_HPP
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <websocketpp/connection.hpp>
#include <list>

#include "ConnectionProtocolHandler.hpp"
#include "RoomManager.hpp"
#include "ClientManager.hpp"

using websocketpp::connection_hdl;
class Server // TODO : SINGLETON
{
public:

	Server();
	void onOpen(connection_hdl hdl);
	void onClose(connection_hdl hdl);
	void run();

private:
	websocketpp::server <websocketpp::config::asio> webSocketServer_;
};
#endif //SERVER_HPP