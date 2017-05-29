//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "NewGameSignal.hpp"
#include "MessageDispatcher.hpp"

void NewGameSignal::acceptDispatcher(MessageDispatcher& dispatcher) {
    dispatcher.dispatch(*this);
}