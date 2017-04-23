#ifndef CLIENT_MANAGER_HPP
#define CLIENT_MANAGER_HPP
#include <list>
#include <string>
#include "Client.hpp"
class ClientManager
{
	bool CheckIfNameAvailable(std::string nickname);
private:
	std::list<Client> client_list;
};
#endif // CLIENT_MANAGER_HPP