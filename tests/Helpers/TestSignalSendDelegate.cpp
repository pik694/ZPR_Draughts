//
// Created by Piotr Żelazko on 02.06.2017.
//

#include <memory>
#include "TestSignalSendDelegate.hpp"
#include "Signals/Signal.hpp"


void TestSignalSendDelegate::sendSignal(std::shared_ptr <Signal> sentSignal) {
    receivedSignals_.push_back(sentSignal);
}

std::shared_ptr<Signal> TestSignalSendDelegate::getSignal() {

    if (receivedSignals_.empty()) return nullptr;

    std::shared_ptr<Signal> tmp (*receivedSignals_.begin());

    receivedSignals_.pop_front();

    return tmp;

}

TestSignalSendDelegate::~TestSignalSendDelegate() {

}
