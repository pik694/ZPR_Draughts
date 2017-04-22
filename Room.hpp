#ifndef ROOM_HPP
#define ROOM_HPP
#include "Client.hpp"
class Client;
class Room
{
public:
	Room();
	bool JoinRoom(Client *player);
private:
	Client *player_1;
	Client *player_2;
	int nr_players;
};
#endif // ROOM_HPP