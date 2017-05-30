#include "Player.hpp"

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
}

void Player::setNickName(std::string nick_a)
{
	nickname_ = nick_a;
}
void Player::setRoom(int room_id_a)
{
	roomID_ = room_id_a;
}

std::string Player::getName()
{
	return nickname_;
}


ConnectionProtocolHandler *Player::getConnectionProtocolHandler() {
	return connectionProtocolHandler_;
}
