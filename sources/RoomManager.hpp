#ifndef ROOM_MANAGER_HPP
#define ROOM_MANAGER_HPP

#include <list>

#include "Room.hpp"

class RoomManager{
public:
    static RoomManager* getInstance();
	/* creates new room and gives it an id */
	Room* addRoom();
	bool deleteRoom(Room*);


private:
    static RoomManager* instance_;

    RoomManager();
	std::list<Room*> rooms_;
};
#endif // ROOM_MANAGER_HPP