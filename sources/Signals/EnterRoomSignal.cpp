//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "EnterRoomSignal.hpp"
#include "MessageDispatcher.hpp"

void EnterRoomSignal::acceptDispatcher(MessageDispatcher& dispatcher){
    dispatcher.dispatch(*this);
}

const std::string& EnterRoomSignal::getRoomID() const {
    return roomID_;
}