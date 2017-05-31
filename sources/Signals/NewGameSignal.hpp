//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP
#define ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP


#include "Signal.hpp"
#include "SignalFactory.hpp"

class NewGameSignal : public Signal {
public:
    NewGameSignal() {}

    NewGameSignal(ConnectionProtocolHandler *hdl) : Signal(hdl) {}

    virtual void acceptDispatcher(MessageDispatcher &);

    virtual void serialize();

private:
    static Register<NewGameSignal> reg;
};


#endif //ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP
