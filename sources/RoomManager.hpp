#ifndef ROOM_MANAGER_HPP
#define ROOM_MANAGER_HPP

#include <list>

#include "Room.hpp"

class RoomManager{
public:
	static RoomManager* getInstance();

	room_ptr getRoom(int id);

	room_ptr newRoom();

	void deleteRoom(Room*);

	RoomManager(const RoomManager&) = delete;
	~RoomManager();

private:
	using room_ptr = std::shared_ptr<Room>;

	static RoomManager* instance_;
	static const size_t  MAX_NUMBER_OF_ROOMS;

	RoomManager();

	int currentRoomID_;
	std::list<room_ptr> rooms_;
};
#endif // ROOM_MANAGER_HPP