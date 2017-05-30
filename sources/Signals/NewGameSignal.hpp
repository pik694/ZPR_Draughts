//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP
#define ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP


#include "Signal.hpp"

class NewGameSignal : public Signal{
public:
    NewGameSignal(ConnectionProtocolHandler* hdl): Signal(hdl){}

    virtual void acceptDispatcher(MessageDispatcher&);
    virtual void serialize();
};


#endif //ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP
