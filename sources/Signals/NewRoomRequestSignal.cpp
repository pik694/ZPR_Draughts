//
// Created by Piotr Żelazko on 29.05.2017.
//
#include <exception>
#include "NewRoomRequestSignal.hpp"

Register<NewRoomRequestSignal> NewRoomRequestSignal::reg("NewRoomRequestSignal");


void NewRoomRequestSignal::fillData(Json::Value data) {
	
}

void NewRoomRequestSignal::acceptDispatcher(MessageDispatcher &dispatcher) {
    dispatcher.dispatch(*this);
}

Json::Value NewRoomRequestSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}
