//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "OpponentLeftRoomSignal.hpp"
#include "MessageDispatcher.hpp"

void OpponentLeftRoomSignal::acceptDispatcher(MessageDispatcher &) {
    throw std::runtime_error("Dispatcher should not dispatch this kind of a signal");
}
