//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "BoardSignal.hpp"

const Board& BoardSignal::getBoard() const {
    return board_;
}

void BoardSignal::acceptDispatcher(MessageDispatcher&){
    throw std::runtime_error("Dispatcher should not dispatch this kind of a signal");
}

void BoardSignal::serialize() {

    throw std::runtime_error("Not implemented yet");

}


