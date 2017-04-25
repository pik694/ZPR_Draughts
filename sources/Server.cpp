#include "Server.hpp"
typedef websocketpp::server<websocketpp::config::asio> server_t;

//Server::Server()
//{
//	web_socket_server.init_asio();
//}
//void Server::on_open(connection_hdl hdl)
//{
//	client_list.push_back(new ConnectionProtocolHandler(manager,my_client_manager,hdl));
//
//}
//void Server::on_close(connection_hdl hdl)
//{
//
//}
//void Server::run()
//{
//	//.listen(8080);
//	//web_socket_server.start_accept();
//}

Server::Server() {
	throw std::runtime_error("Not implemented yet");
}
void Server::onOpen(connection_hdl hdl) {
	throw std::runtime_error("Not implemented yet");
}
void Server::onClose(connection_hdl hdl) {
	throw std::runtime_error("Not implemented yet");
}
void Server::run() {
	throw std::runtime_error("Not implemented yet");
}