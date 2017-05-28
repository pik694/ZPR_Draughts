//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_SIGNAL_HPP
#define ZPR_DRAUGHTS_SIGNAL_HPP

#include "../MessageDispatcher.hpp"
#include <string>
class Signal {

public:
	std::string type;
    virtual void acceptDispatcher(const MessageDispatcher& dispatcher) = 0;
    virtual ~Signal();
};


#endif //ZPR_DRAUGHTS_SIGNAL_HPP
