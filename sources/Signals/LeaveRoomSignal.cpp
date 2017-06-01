//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "LeaveRoomSignal.hpp"
#include "MessageDispatcher.hpp"

Register<LeaveRoomSignal> LeaveRoomSignal::reg("LeaveRoomSignal");

void LeaveRoomSignal::acceptDispatcher(MessageDispatcher &dispatcher) {
    dispatcher.dispatch(*this);
}

Json::Value LeaveRoomSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}
