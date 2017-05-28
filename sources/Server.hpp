#ifndef SERVER_HPP
#define SERVER_HPP
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <websocketpp/connection.hpp>
#include <iostream>
#include <list>
#include <set>
#include "Action.hpp"
#include "ConnectionProtocolHandler.hpp"
#include "RoomManager.hpp"
#include "ClientManager.hpp"

using websocketpp::connection_hdl;
using websocketpp::lib::mutex;
using websocketpp::lib::condition_variable;
typedef websocketpp::server<websocketpp::config::asio> server;
typedef server::message_ptr message_ptr;
//typedef websocketpp::server<websocketpp::config::asio> server_t;
class Server // TODO : SINGLETON
{
public:

	Server();
	~Server();
	void onOpen(connection_hdl hdl);
	void onClose(connection_hdl hdl);
	void onMessage(connection_hdl hdl, message_ptr msg);
	void run(int port);
	void processMessages();
	static mutex m_action_lock;
private:
	websocketpp::server <websocketpp::config::asio> webSocketServer_;
	std::list<ConnectionProtocolHandler*> connections_;
	typedef std::set<connection_hdl,std::owner_less<connection_hdl> > con_list;

    con_list m_connections;
    std::queue<Action> m_actions;

    mutex m_connection_lock;
    condition_variable m_action_cond;

};
#endif //SERVER_HPP