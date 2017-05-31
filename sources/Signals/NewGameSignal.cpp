//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "NewGameSignal.hpp"
#include "MessageDispatcher.hpp"

Register<NewGameSignal> NewGameSignal::reg("NewGameSignal");

void NewGameSignal::acceptDispatcher(MessageDispatcher &dispatcher) {
    dispatcher.dispatch(*this);
}

void NewGameSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}
