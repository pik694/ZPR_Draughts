#ifndef CLIENT_MANAGER_HPP
#define CLIENT_MANAGER_HPP

#include <list>
#include <string>

#include "Player.hpp"


class ClientManager
// TODO: SINGLETON
{
	bool checkIfNameAvailable(const std::string& nickname);


private:
	std::list<Player*> clients_;
};
#endif // CLIENT_MANAGER_HPP