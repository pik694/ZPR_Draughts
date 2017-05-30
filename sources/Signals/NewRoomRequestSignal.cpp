//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "NewRoomRequestSignal.hpp"
#include "MessageDispatcher.hpp"

const std::string& NewRoomRequestSignal::getRoomID() const {
    return roomID_;
}


void NewRoomRequestSignal::acceptDispatcher(MessageDispatcher& dispatcher) {
    dispatcher.dispatch(*this);
}

void NewRoomRequestSignal::serlialize() {
    throw std::runtime_error("Not implemented yet");
}
