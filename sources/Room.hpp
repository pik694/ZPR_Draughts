#ifndef ROOM_HPP
#define ROOM_HPP


#include "GameObserver.hpp"
#include "GameLogic/Game.hpp"



class Room : public GameObserver
{
public:

	Room (int);

	bool joinRoom(player_ptr);
	void leaveRoom(player_ptr);

	int getRoomID();

	void playerWon(PlayerColour);
	void startNewGame();



	void sendTextMessage(player_ptr ,const std::string&);

private:
	using player_ptr = std::shared_ptr<Player>;

	const int roomID_;

	player_ptr whitePlayer_;
	player_ptr blackPlayer_;

	int numberOfPlayers_;

	Game game_;

};

#endif // ROOM_HPP