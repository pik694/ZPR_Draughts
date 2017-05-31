#include "RoomManager.hpp"

RoomManager *RoomManager::instance_ = nullptr;
const size_t RoomManager::MAX_NUMBER_OF_ROOMS = 32;

RoomManager *RoomManager::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new RoomManager();
    }

    return instance_;
}

RoomManager::room_ptr RoomManager::getRoom(int id) {

    for (auto room : rooms_) {
        if (room->getRoomID() == id) return room;
    }

    return nullptr;

}

RoomManager::room_ptr RoomManager::newRoom() {

    if (rooms_.size() == MAX_NUMBER_OF_ROOMS)
        throw std::runtime_error("Maximum number of rooms has already been achieved");

    rooms_.push_front(std::make_shared<Room>(currentRoomID_++));

    return rooms_.front();
}

void RoomManager::deleteRoom(Room *room) {

    rooms_.remove_if(
            [room](RoomManager::room_ptr currRoom) -> bool {
                return currRoom.get() == room;
            });
}


RoomManager::~RoomManager() {

}

RoomManager::RoomManager() : currentRoomID_(0), rooms_() {}
