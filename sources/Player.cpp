#include "Player.hpp"
#include "ConnectionProtocolHandler.hpp"
using room_ptr = std::shared_ptr<Room>;
int Player::clientIds_ = 0;
Player::Player()
{
	nickname_ = "";
	clientID_ = clientIds_;
	++clientIds_;

	connectionProtocolHandler_ = nullptr;


	//TODO: throw std::runtime_error("This constructor should not be invoked");
}

Player::Player(std::string nick, ConnectionProtocolHandler *hdl) {

	nickname_ = nick;
	clientID_ = clientIds_;
	++clientIds_;

	connectionProtocolHandler_ = hdl;

	room_ = nullptr;

}

Player::~Player() {

}
void Player::setNickName(std::string nick_a)
{
	nickname_ = nick_a;
}
void Player::setRoom(Room* room){
	 room_ = room;
}

void Player::setRoom(int roomID){
	 throw std::runtime_error("not implemented yet");
}

int getRoomID() {
	throw std::runtime_error("not implemented yet");
}
room_ptr Player::getRoom() {
	throw std::runtime_error("not implemented yet");
}

std::string Player::getName()
{
	return nickname_;
}


ConnectionProtocolHandler *Player::getConnectionProtocolHandler() {
	return connectionProtocolHandler_;
}
