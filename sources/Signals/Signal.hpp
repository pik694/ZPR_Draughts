//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_SIGNAL_HPP
#define ZPR_DRAUGHTS_SIGNAL_HPP

#include <jsoncpp/json/json.h>
#include "ConnectionProtocolHandler.hpp"
#include "MessageDispatcher.hpp"

class Signal {
public:
	Signal() {} //TODO : this constructor should not be used
    Signal(ConnectionProtocolHandler* hdl);

    virtual void acceptDispatcher(MessageDispatcher &) = 0;

    virtual void fillData(Json::Value data) {}

    virtual void fillProtocolHandler(ConnectionProtocolHandler *);
    virtual Json::Value serialize() {return nullptr;}

    virtual ~Signal() {}

    virtual ConnectionProtocolHandler* getConnectionProtocolHandler();

private:
    ConnectionProtocolHandler* connectionProtocolHandler_;

};


#endif //ZPR_DRAUGHTS_SIGNAL_HPP
