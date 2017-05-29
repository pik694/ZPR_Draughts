//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "NickRequestSignal.hpp"
#include "MessageDispatcher.hpp"

const std::string& NickRequestSignal::getNick() const {
    return nick_;
}

void NickRequestSignal::acceptDispatcher(MessageDispatcher& dispatcher){
    dispatcher.dispatch(*this);
}