//
// Created by Piotr Żelazko on 02.06.2017.
//

#include <memory>
#include "TestSignalSendDelegate.hpp"
#include "Signals/Signal.hpp"


void TestSignalSendDelegate::sendSignal(std::shared_ptr <Signal>) {
    throw std::runtime_error("Not implemented yet");
}

TestSignalSendDelegate::~TestSignalSendDelegate() {

}
