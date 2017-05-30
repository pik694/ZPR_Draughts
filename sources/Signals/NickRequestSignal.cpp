//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "NickRequestSignal.hpp"
#include "MessageDispatcher.hpp"

Register<NickRequestSignal> NickRequestSignal::reg("nickRequest");

const std::string& NickRequestSignal::getNick() const {
    return nick_;
}

void NickRequestSignal::acceptDispatcher(MessageDispatcher& dispatcher){
    dispatcher.dispatch(*this);
}

void NickRequestSignal::fillData(Json::Value data) {
	nick_ = data.get("type","").asString();
}