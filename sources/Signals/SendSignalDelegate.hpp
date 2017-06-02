//
// Created by Piotr Żelazko on 02.06.2017.
//

#ifndef ZPR_DRAUGHTS_SENDSIGNALDELEGATE_HPP
#define ZPR_DRAUGHTS_SENDSIGNALDELEGATE_HPP

#include "Signal.hpp"

class SendSignalDelegate {

public:

    SendSignalDelegate();

    int getNumberOfSentSignals();

    virtual void sendSignal(std::shared_ptr<Signal>);

    virtual ~SendSignalDelegate();

private:

    int signalsSent_;

};


#endif //ZPR_DRAUGHTS_SENDSIGNALDELEGATE_HPP
