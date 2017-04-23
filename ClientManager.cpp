#include "ClientManager.hpp"

bool ClientManager::CheckIfNameAvailable(std::string nickname)
{
	for(auto i : client_list)
	{
		if(nickname == i->GetName())
			return false;
		return true;
	}
}