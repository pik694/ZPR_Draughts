//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_SIGNAL_HPP
#define ZPR_DRAUGHTS_SIGNAL_HPP


class MessageDispatcher;

class Signal {
public:

    virtual void acceptDispatcher (MessageDispatcher) = 0;
    virtual ~Signal();
};

#include "MessageDispatcher.hpp"


#endif //ZPR_DRAUGHTS_SIGNAL_HPP
