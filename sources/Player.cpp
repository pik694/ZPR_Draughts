#include "Player.hpp"

int Player::clientIds_ = 0;
Player::Player()
{
	nickname_ = "";
	clientID_ = clientIds_;
	++clientIds_;
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