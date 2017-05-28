//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
#define ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
#include <iostream>
#include "Signals/Signal.hpp"
#include "Signals/NickRequestSignal.hpp"

class MessageDispatcher {
public:
	void visit(NickRequestSignal *message);
};


#endif //ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
