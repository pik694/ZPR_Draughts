//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "EnterRoomSignal.hpp"


void EnterRoomSignal::acceptDispatcher(MessageDispatcher dispatcher){
    dispatcher.visit(*this);
}

const std::string& EnterRoomSignal::getRoomID() const {
    return roomID_;
}