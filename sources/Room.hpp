#ifndef ROOM_HPP
#define ROOM_HPP


#include "GameObserver.hpp"
#include "GameLogic/Game.hpp"
#include "GameLogic/PlayerColour.hpp"



class Room : public GameObserver
{

	using player_ptr = std::shared_ptr<Player>;
public:

	Room (int);

	bool joinRoom(player_ptr);
	bool leaveRoom(player_ptr);

	int getRoomID();

	void playerWon(PlayerColour);
	void startNewGame();

    void makeMove(const std::vector<Point>&, player_ptr);



	void sendTextMessage(player_ptr ,const std::string&);

private:

	const int roomID_;

	player_ptr whitePlayer_;
	player_ptr blackPlayer_;

	int numberOfPlayers_;

	Game game_;

};

#endif // ROOM_HPP