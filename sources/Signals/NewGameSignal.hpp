//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP
#define ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP


#include "Signal.hpp"

class NewGameSignal : public Signal{
public:
    virtual void acceptDispatcher(MessageDispatcher dispatcher);
};


#endif //ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP
