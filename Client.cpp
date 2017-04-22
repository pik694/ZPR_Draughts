#include "Client.hpp"

Client::Client(RoomManager *manager_a,connection_hdl &client_connection_a)
{
	client_connection =  client_connection_a;
	manager = manager_a;
	client_connection->set_message_handler(&Client::ClientTalker);
}

void Client::ClientTalker(connection_hdl hdl,websocketpp::server<websocketpp::config::asio>::message_ptr msg)
{

}