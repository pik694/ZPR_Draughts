#ifndef ROOM_HPP
#define ROOM_HPP


#include "GameObserver.hpp"
#include "GameLogic/Game.hpp"



class Room : public GameObserver
{
public:

	Room (int);

	bool joinRoom(Player*);
	void leaveRoom(Player*);

	int getRoomID();

	void playerWon(PlayerColour);


	void sendTextMessage(Player*, std::string);

private:


	const int roomID_;

	Player* whitePlayer_;
	Player* blackPlayer_;

	int numberOfPlayers_;

	Game game_;
	bool end_;

};

#endif // ROOM_HPP