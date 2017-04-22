#ifndef ROOM_MANAGER_HPP
#define ROOM_MANAGER_HPP
#include <list>
#include "Room.hpp"
class Room;
class RoomManager
{
public:
	RoomManager();
	/* creates new room and gives it an id */
	Room* AddRoom();
	void DeleteRoom(Room *);
private:
	std::list<Room*> room_list;
};
#endif // ROOM_MANAGER_HPP