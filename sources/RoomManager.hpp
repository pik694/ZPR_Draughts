#ifndef ROOM_MANAGER_HPP
#define ROOM_MANAGER_HPP

#include <list>

#include "Room.hpp"

class RoomManager{
public:
	static RoomManager* getInstance();

	Room* getRoom(int id);

	Room* newRoom();

	bool deleteRoom(Room*);
	bool deleteRoom(int id);



	RoomManager(const RoomManager&) = delete;
	~RoomManager();
private:
	static RoomManager* instance_;

	RoomManager();

	int currentRoomID_;
	std::list<Room*> rooms_;
};
#endif // ROOM_MANAGER_HPP