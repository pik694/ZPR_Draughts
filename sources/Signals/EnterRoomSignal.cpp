//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "EnterRoomSignal.hpp"
#include "MessageDispatcher.hpp"

void EnterRoomSignal::acceptDispatcher(MessageDispatcher& dispatcher){
    dispatcher.dispatch(*this);
}

int EnterRoomSignal::getRoomID() const {
    return roomID_;
}

void EnterRoomSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}
