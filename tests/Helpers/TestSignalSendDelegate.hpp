//
// Created by Piotr Żelazko on 02.06.2017.
//

#ifndef ZPR_DRAUGHTS_TESTSIGNALSENDDELEGATE_HPP
#define ZPR_DRAUGHTS_TESTSIGNALSENDDELEGATE_HPP


#include <Signals/SendSignalDelegate.hpp>

class TestSignalSendDelegate : public SendSignalDelegate {

    virtual void sendSignal(std::shared_ptr<Signal>);

    virtual ~TestSignalSendDelegate();

};


#endif //ZPR_DRAUGHTS_TESTSIGNALSENDDELEGATE_HPP
