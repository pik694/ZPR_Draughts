//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "NickRequestSignal.hpp"
#include "MessageDispatcher.hpp"

Register<NickRequestSignal> NickRequestSignal::reg("NickRequestSignal");

const std::string &NickRequestSignal::getNick() const {
    return nick_;
}

void NickRequestSignal::acceptDispatcher(MessageDispatcher &dispatcher) {
    dispatcher.dispatch(*this);
}

Json::Value NickRequestSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}

void NickRequestSignal::fillData(Json::Value data) {
    nick_ = data.get("value", "").asString();
}