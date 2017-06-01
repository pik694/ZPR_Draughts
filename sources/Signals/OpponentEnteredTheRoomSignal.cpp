//
// Created by Piotr Żelazko on 29.05.2017.
//


#include "OpponentEnteredTheRoomSignal.hpp"

Register<OpponentEnteredTheRoomSignal> OpponentEnteredTheRoomSignal::reg("OpponentEnteredTheRoomSignal");

void OpponentEnteredTheRoomSignal::acceptDispatcher(MessageDispatcher &) {
    throw std::runtime_error("Dispatcher should not dispatch this kind of a signal");
}

const std::string &OpponentEnteredTheRoomSignal::getOpponentNick() const {
    return opponentNick_;
}

Json::Value OpponentEnteredTheRoomSignal::serialize() {
    Json::Value answer;
    answer["type"] = "OpponentEnteredTheRoomSignal";
    answer["value"] = opponentNick_;
    return answer;
}
