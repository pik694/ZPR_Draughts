#include "RoomManager.hpp"

RoomManager::RoomManager() {}
	/* creates new room and gives it an id */
Room* RoomManager::addRoom()
{
	Room* newRoom = new Room();
	rooms_.push_back(newRoom);
	return newRoom;
}
void RoomManager::deleteRoom(Room* toBeDeleted)
{
	rooms_.remove(toBeDeleted);
	delete toBeDeleted;
}
