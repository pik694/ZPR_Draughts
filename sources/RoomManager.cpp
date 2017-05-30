#include "RoomManager.hpp"

RoomManager::RoomManager() {
	throw std::runtime_error("Not implemented yet");
}

Room* RoomManager::newRoom()
{
	throw std::runtime_error("Not implemented yet");
}
bool RoomManager::deleteRoom(Room* toBeDeleted)
{
	throw std::runtime_error("Not implemented yet");
}

RoomManager* RoomManager::getInstance() {
	if (instance_ == nullptr){
		instance_ = new RoomManager();
	}

	return instance_;

}