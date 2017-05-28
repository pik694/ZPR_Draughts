//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "NewRoomRequestSignal.hpp"

const std::string& NewRoomRequestSignal::getRoomID() const {
    return roomID_;
}


void NewRoomRequestSignal::acceptDispatcher(MessageDispatcher dispatcher) {
    dispatcher.visit(*this);
}