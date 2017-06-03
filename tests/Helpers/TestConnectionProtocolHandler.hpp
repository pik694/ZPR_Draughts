//
// Created by Piotr Żelazko on 02.06.2017.
//

#ifndef ZPR_DRAUGHTS_TESTCONNECTIONPROTOCOLHANDLER_HPP
#define ZPR_DRAUGHTS_TESTCONNECTIONPROTOCOLHANDLER_HPP


#include <ConnectionProtocolHandler.hpp>

using websocketpp::connection_hdl;

class TestConnectionProtocolHandler : public ConnectionProtocolHandler {
public:

    TestConnectionProtocolHandler(): ConnectionProtocolHandler(*(new connection_hdl())){} // Memory leak but only on test purposes


};


#endif //ZPR_DRAUGHTS_TESTCONNECTIONPROTOCOLHANDLER_HPP
