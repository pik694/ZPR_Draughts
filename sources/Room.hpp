#ifndef ROOM_HPP
#define ROOM_HPP

#include <memory>

#include "Player.hpp"
#include "Game.hpp"




class Player;
class Room : public GameObserver
{
public:

	Room();
	bool joinRoom(const Player&);

    void leaveRoom(const Player&);

private:

	std::shared_ptr<Player> player1_;
	std::shared_ptr<Player> player2_;
	int nrPlayers_;
	Game game_;
};
#endif // ROOM_HPP