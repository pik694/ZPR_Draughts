//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP


#include "Signals/Signal.hpp"

class OpponentLeftRoomSignal : public Signal {

public:
    void acceptDispatcher(MessageDispatcher dispatcher){
        throw std::runtime_error("Dispatcher should not dispatch this kind of signal");
    }

};


#endif //ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP
