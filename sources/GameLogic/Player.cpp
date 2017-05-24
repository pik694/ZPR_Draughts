#include "Player.hpp"

int Player::clientIds_ = 0;
Player::Player()
{
	throw std::runtime_error("Not implemented yet");
	nickname_ = "";
	clientID_ = clientIds_;
	++clientIds_;
}

void Player::setNickName(std::string nick_a)
{
	throw std::runtime_error("Not implemented yet");
	nickname_ = nick_a;
}
void Player::setRoom(int room_id_a)
{
	throw std::runtime_error("Not implemented yet");
	roomID_ = room_id_a;
}

std::string Player::getName()
{
	throw std::runtime_error("Not implemented yet");
	return nickname_;
}