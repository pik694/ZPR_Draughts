//
// Created by Piotr Żelazko on 30.05.2017.
//


#include "Signal.hpp"

Signal::Signal(ConnectionProtocolHandler *hdl) {
    connectionProtocolHandler_ = hdl;
}

ConnectionProtocolHandler *Signal::getConnectionProtocolHandler() {
    return connectionProtocolHandler_;
}

void Signal::fillProtocolHandler(ConnectionProtocolHandler *connectionProtocolHandler) {
	connectionProtocolHandler_ = connectionProtocolHandler;
}