//
// Created by Piotr Żelazko on 02.06.2017.
//

#ifndef ZPR_DRAUGHTS_TESTSIGNALSENDDELEGATE_HPP
#define ZPR_DRAUGHTS_TESTSIGNALSENDDELEGATE_HPP


#include <Signals/SendSignalDelegate.hpp>
#include <list>

class TestSignalSendDelegate : public SendSignalDelegate {
public:
    virtual void sendSignal(std::shared_ptr<Signal>);

    virtual ~TestSignalSendDelegate();

    std::shared_ptr<Signal> getSignal();

private:

    std::list<std::shared_ptr<Signal>> receivedSignals_;

};


#endif //ZPR_DRAUGHTS_TESTSIGNALSENDDELEGATE_HPP
