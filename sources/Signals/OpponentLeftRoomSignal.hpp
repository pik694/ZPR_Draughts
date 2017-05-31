//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP


#include "Signals/Signal.hpp"
#include "SignalFactory.hpp"
#include <string>

class OpponentLeftRoomSignal : public Signal {
public:
	OpponentLeftRoomSignal() {}
    OpponentLeftRoomSignal(ConnectionProtocolHandler* hdl):Signal(hdl){}

    virtual void acceptDispatcher(MessageDispatcher&);
    virtual void serialize();
private:
	static Register<OpponentLeftRoomSignal> reg;
};


#endif //ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP
