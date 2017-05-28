#ifndef ROOM_HPP
#define ROOM_HPP


#include "GameObserver.hpp"
#include "GameLogic/Game.hpp"



class Room : public GameObserver
{
public:

	Room ();

	bool joinRoom(const Player*);
    void leaveRoom(const Player*);

	void playerWon(const Player*);


private:
    using player_ptr = std::shared_ptr<const Player>;



    player_ptr whitePlayer_;
    player_ptr blackPlayer_;

	int numberOfPlayers_;
};

#endif // ROOM_HPP