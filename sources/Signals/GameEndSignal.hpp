//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP
#define ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP


#include "Signals/Signal.hpp"

#include "SignalFactory.hpp"
class GameEndSignal : public Signal {
public:
	GameEndSignal() : won_(false) {}
    GameEndSignal(ConnectionProtocolHandler* hdl, bool won):Signal(hdl), won_(won){}

    const bool getWon() const {
        return won_;
    }

    virtual void acceptDispatcher(MessageDispatcher&);


private:
    const bool won_;
    static Register<GameEndSignal> reg;
};


#endif //ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP
