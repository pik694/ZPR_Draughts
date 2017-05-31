//
// Created by Piotr Żelazko on 30.05.2017.
//


#include "Signal.hpp"
#include "ConnectionProtocolHandler.hpp"

Signal::Signal(ConnectionProtocolHandler *hdl) {
    connectionProtocolHandler_ = hdl;
}

ConnectionProtocolHandler *Signal::getConnectionProtocolHandler() {
    return connectionProtocolHandler_;
}