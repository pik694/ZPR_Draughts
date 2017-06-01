//
// Created by Piotr Żelazko on 01.06.2017.
//

#include "RoomsRequestSignal.hpp"
#include "MessageDispatcher.hpp"

RoomsRequestSignal::RoomsRequestSignal(ConnectionProtocolHandler* hdl): Signal(hdl) {}

void RoomsRequestSignal::acceptDispatcher(MessageDispatcher& dispatcher) {
        dispatcher.dispatch(*this);
}
