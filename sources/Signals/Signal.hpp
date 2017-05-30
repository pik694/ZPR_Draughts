//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_SIGNAL_HPP
#define ZPR_DRAUGHTS_SIGNAL_HPP

#include <jsoncpp/json/json.h>
#include <ConnectionProtocolHandler.hpp>

class MessageDispatcher;

class Signal {
public:

    Signal(ConnectionProtocolHandler* hdl = nullptr): connectionProtocolHandler_(hdl){}

    virtual void acceptDispatcher (MessageDispatcher&) = 0;
    virtual void fillData(Json::Value data) = 0;
    virtual ~Signal(){}

    ConnectionProtocolHandler* getConnectionProtocolHandler(){
        return connectionProtocolHandler_;
    }
private:
    ConnectionProtocolHandler* connectionProtocolHandler_;

};


#endif //ZPR_DRAUGHTS_SIGNAL_HPP
