//
// Created by Piotr Żelazko on 02.06.2017.
//

#include "SendSignalDelegate.hpp"
#include "Server.hpp"

SendSignalDelegate::SendSignalDelegate(): signalsSent_(0) {}

void SendSignalDelegate::sendSignal(std::shared_ptr<Signal> signal) {

    ++signalsSent_;
    Server::getInstance()->putMessageInQueue(signal);
}


int SendSignalDelegate::getNumberOfSentSignals() {
    return signalsSent_;
}

SendSignalDelegate::~SendSignalDelegate() {}
