//
// Created by Piotr Żelazko on 31.05.2017.
//

#include "MoveSignal.hpp"
#include "MessageDispatcher.hpp"

const std::vector<Point> &MoveSignal::getMove() const {
    return move_;
}

void MoveSignal::fillData(Json::Value) {
    throw std::runtime_error("Not implemented yet");
}

void MoveSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}


void MoveSignal::acceptDispatcher(MessageDispatcher& dispatcher) {
    dispatcher.dispatch(*this);
}
