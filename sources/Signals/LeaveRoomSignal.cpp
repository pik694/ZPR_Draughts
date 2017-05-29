//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "LeaveRoomSignal.hpp"
#include "MessageDispatcher.hpp"

void LeaveRoomSignal::acceptDispatcher(MessageDispatcher& dispatcher) {
    dispatcher.dispatch(*this);
}
