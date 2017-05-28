//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_SIGNAL_HPP
#define ZPR_DRAUGHTS_SIGNAL_HPP

//#include "../MessageDispatcher.hpp"
#include <string>
class MessageDispatcher;
class Signal {

public:
    virtual void acceptDispatcher(MessageDispatcher& dispatcher) = 0;
};


#endif //ZPR_DRAUGHTS_SIGNAL_HPP
