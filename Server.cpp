#include "Server.hpp"
typedef websocketpp::server<websocketpp::config::asio> server_t;
Server::Server()
{
	web_socket_server.init_asio();
}
void Server::on_open(connection_hdl hdl)
{
	
	std::lock_guard<std::mutex> lock(m_mutex);
	client_list.push_back(new Client(&manager,hdl));

}
void Server::on_close(connection_hdl hdl)
{
		// remove from conenction_list
		// thread should exit gracefully
	std::lock_guard<std::mutex> lock(m_mutex);
		//connection_list.remove();
}
void Server::run()
{
	web_socket_server.listen(8080);
	web_socket_server.start_accept();
}