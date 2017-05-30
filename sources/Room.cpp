#include "Room.hpp"

Room::Room(int ID):
		whitePlayer_(nullptr),
		blackPlayer_(nullptr),
		numberOfPlayers_(0),
		roomID_(ID),
		end_(false) {}



bool Room::joinRoom(Player* player) {

	if (numberOfPlayers_ == 2) return false;

	if (whitePlayer_ == nullptr){
		whitePlayer_ = player;
	}
	else {
		blackPlayer_ = player;
	}

	if (numberOfPlayers_ == 1){
		Player* opponent;
		if (whitePlayer_ != player){
			opponent = whitePlayer_;
		}
		else {
			opponent = blackPlayer_;
		}

		//TODO: send singal : opponent entered room
	}

	player->setRoom(roomID_);

	++numberOfPlayers_;


}

void Room::leaveRoom(Player* player) {

	bool removed = false;
	if (whitePlayer_ == player){
		whitePlayer_ = nullptr;
		removed = true;
	}
	else if (blackPlayer_ == player){
		blackPlayer_ = nullptr;
		removed = true;
	}

	if (removed){
		if (whitePlayer_ != nullptr) ; //TODO: send signal
		else if (blackPlayer_ != nullptr) ; //TODO: send signal
		player->setRoom(-1);
		--numberOfPlayers_;
	}

	end_ = true;


}

void Room::playerWon(PlayerColour colour) {

	Player* won;
	Player* lost;

	if (colour == PlayerColour::white){
		won = whitePlayer_;
		lost = blackPlayer_;
	}
	else{
		won = blackPlayer_;
		lost = whitePlayer_;
	}

	end_ = true;

	//TODO: send messages

}