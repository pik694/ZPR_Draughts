//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_SIGNAL_HPP
#define ZPR_DRAUGHTS_SIGNAL_HPP

#include <jsoncpp/json/json.h>


class ConnectionProtocolHandler;

class MessageDispatcher;

class Signal {
public:

    Signal(ConnectionProtocolHandler *hdl = nullptr);

    virtual void acceptDispatcher(MessageDispatcher &) = 0;

    virtual void fillData(Json::Value data) {}

    virtual void serialize() {}

    virtual ~Signal() {}

    ConnectionProtocolHandler *getConnectionProtocolHandler();

private:
    ConnectionProtocolHandler *connectionProtocolHandler_;

};


#endif //ZPR_DRAUGHTS_SIGNAL_HPP
