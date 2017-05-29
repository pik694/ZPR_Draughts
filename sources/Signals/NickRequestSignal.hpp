//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP

#include <string>
#include "Signals/Signal.hpp"
#include "SignalFactory.hpp"
class NickRequestSignal : public Signal{
public:

    NickRequestSignal() {}

    void fillData(Json::Value data);

    const std::string& getNick() const;

    void acceptDispatcher(MessageDispatcher&);


private:
    std::string nick_;
    static Register<NickRequestSignal> reg;
};


#endif //ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
