#include "RoomManager.hpp"

RoomManager::RoomManager() {}
	/* creates new room and gives it an id */
Room* RoomManager::AddRoom()
{
	Room *tmp = new Room;
	room_list.push_back(tmp);
	return tmp;
}
void RoomManager::DeleteRoom(Room *tmp)
{
	room_list.remove(tmp);
	delete tmp;
}