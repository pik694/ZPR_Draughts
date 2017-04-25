#include "RoomManager.hpp"

RoomManager::RoomManager() {
	throw std::runtime_error("Not implemented yet");
}
	/* creates new room and gives it an id */
Room* RoomManager::addRoom()
{
	throw std::runtime_error("Not implemented yet");
	Room* newRoom = new Room();
	rooms_.push_back(newRoom);
	return newRoom;
}
bool RoomManager::deleteRoom(Room* toBeDeleted)
{
	throw std::runtime_error("Not implemented yet");
	rooms_.remove(toBeDeleted);
	delete toBeDeleted;
}

RoomManager* RoomManager::getInstance() {
	throw std::runtime_error("Not implemented yet");
}