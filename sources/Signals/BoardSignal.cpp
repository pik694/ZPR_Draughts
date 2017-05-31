//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "BoardSignal.hpp"
Register<BoardSignal> BoardSignal::reg("BoardSignal");
const Board& BoardSignal::getBoard() const {
    return board_;
}

void BoardSignal::acceptDispatcher(MessageDispatcher&){
    throw std::runtime_error("Dispatcher should not dispatch this kind of a signal");
}

void BoardSignal::serialize() {

    throw std::runtime_error("Not implemented yet");

}

const bool BoardSignal::isPlayersMove() const {
    return isPlayersMove_;
}


