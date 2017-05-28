//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "LeaveRoomSignal.hpp"

void LeaveRoomSignal::acceptDispatcher(MessageDispatcher dispatcher) {
    dispatcher.visit(*this);
}
