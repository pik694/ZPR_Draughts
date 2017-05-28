//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP
#define ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP


#include "Signals/Signal.hpp"

class GameEndSignal : public Signal {
public:
    GameEndSignal(bool won): won_(won){}

    const bool getWon() const {
        return won_;
    }

    virtual void acceptDispatcher(MessageDispatcher dispatcher) {
        throw std::runtime_error("Dispatcher should not dispatch this kind of signal");
    }


private:
    const bool won_;
};


#endif //ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP
