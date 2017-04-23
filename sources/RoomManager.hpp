#ifndef ROOM_MANAGER_HPP
#define ROOM_MANAGER_HPP
#include <list>
#include "Room.hpp"
class Room;
class RoomManager
{ // TODO : SINGLETON
public:
	RoomManager();
	/* creates new room and gives it an id */
	Room* addRoom();
	void deleteRoom(Room*);


private:
	std::list<Room*> roomList_;
};
#endif // ROOM_MANAGER_HPP