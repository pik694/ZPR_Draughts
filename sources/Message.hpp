//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_MESSAGE_HPP
#define ZPR_DRAUGHTS_MESSAGE_HPP

#include "MessageDispatcher.hpp"

class Message {

    virtual void acceptDispatcher(const MessageDispatcher& dispatcher)= 0;

    virtual ~Message();
};


#endif //ZPR_DRAUGHTS_MESSAGE_HPP
