#include "Room.hpp"

Room::Room(): player1_(nullptr), player2_(nullptr), numberOfPlayers_(0)
{
}
bool Room::joinRoom(const Player *player)
{
	if(numberOfPlayers_ >= 2)
		return false;

	if(player1_ != nullptr)
	{
		player1_ = player;
		return true;
	}
	player2_ = player;
	++numberOfPlayers_;
	return true;
}
