#include "Room.hpp"

Room::Room()
{
	player_1 = nullptr;
	player_2 = nullptr;
	nr_players = 0;
}
bool Room::JoinRoom(Client *player)
{
	if(nr_players >= 2)
		return false;

	if(player_1 != nullptr)
	{
		player_1 = player;
		return true;
	}
	player_2 = player;
	++nr_players;
	return true;
}