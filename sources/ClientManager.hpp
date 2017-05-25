#ifndef CLIENT_MANAGER_HPP
#define CLIENT_MANAGER_HPP

#include <list>
#include <string>

#include "Player.hpp"


class ClientManager
// TODO: SINGLETON
{
public:
	bool addNewPlayer(const std::string &nickname);
	bool checkIfNameAvailable(const std::string& nickname);
	static ClientManager *getInstance();

private:
	std::list<Player*> clients_;
};
#endif // CLIENT_MANAGER_HPP