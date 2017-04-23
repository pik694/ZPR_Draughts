
#include <list>
#include <string>
#include "Client.hpp"
class ClientManager
{
	bool CheckIfNameAvailable(std::string nickname);
private:
	std::list<Client> client_list;
};