//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "OpponentLeftRoomSignal.hpp"
#include "MessageDispatcher.hpp"

Register<OpponentLeftRoomSignal> OpponentLeftRoomSignal::reg("OpponentLeftRoomSignal");

void OpponentLeftRoomSignal::acceptDispatcher(MessageDispatcher &) {
    throw std::runtime_error("Dispatcher should not dispatch this kind of a signal");
}

Json::Value OpponentLeftRoomSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}
