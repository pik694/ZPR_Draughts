//
// Created by Piotr Żelazko on 29.05.2017.
//
#include <exception>
#include "NewRoomRequestSignal.hpp"
#include "MessageDispatcher.hpp"

Register<NewRoomRequestSignal> NewRoomRequestSignal::reg("NewRoomRequestSignal");

const std::string &NewRoomRequestSignal::getRoomID() const {
    return roomID_;
}

void NewRoomRequestSignal::fillData(Json::Value data) {
	try {
		roomID_ = data.get("value", -1).asInt();
	}
	catch(std::exception &e) {
		std::cout<<"error reading room name"<<std::endl;
	}
}

void NewRoomRequestSignal::acceptDispatcher(MessageDispatcher &dispatcher) {
    dispatcher.dispatch(*this);
}

Json::Value NewRoomRequestSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}
