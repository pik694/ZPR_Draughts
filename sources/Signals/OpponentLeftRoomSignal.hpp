//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP


#include "Signals/Signal.hpp"
#include <string>

class OpponentLeftRoomSignal : public Signal {
public:
    virtual void acceptDispatcher(MessageDispatcher&);
};


#endif //ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP
