#ifndef ROOM_HPP
#define ROOM_HPP


#include "GameObserver.hpp"
#include "GameLogic/Game.hpp"



class Room : public GameObserver
{
public:

	Room ();

	bool joinRoom(const Player* );
    void leaveRoom(const Player*);

	void playerWon(const Player*);


private:

	const Player* player1_;
    const Player* player2_;

	int numberOfPlayers_; //
	std::unique_ptr <Game> game_;

};

#endif // ROOM_HPP