#include "Player.hpp"

int Player::client_ids = 0;
Player::Player()
{
	nickname = "";
	client_id = client_ids;
	++client_ids;
}

void Player::SetNickName(std::string nick_a)
{
	nickname = nick_a;
}
void Player::SetRoom(int room_id_a)
{
	room_id = room_id_a;
}

bool Player::operator==(const Player &arg)
{
	return arg.client_id == client_id;
}

std::string Player::GetName()
{
	return nickname;
}