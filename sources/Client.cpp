#include "Client.hpp"

int Client::client_ids = 0;
Client::Client()
{
	nickname = "";
	client_id = client_ids;
	++client_ids;
}

void Client::SetNickName(std::string nick_a)
{
	nickname = nick_a;
}
void Client::SetRoom(int room_id_a)
{
	room_id = room_id_a;
}

bool Client::operator==(const Client &arg)
{
	return arg.client_id == client_id;
}

std::string Client::GetName()
{
	return nickname;
}