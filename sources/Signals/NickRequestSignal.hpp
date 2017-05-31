//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP

#include <string>
#include "Signals/Signal.hpp"
#include "SignalFactory.hpp"

class NickRequestSignal : public Signal {
public:
    NickRequestSignal() {}

    NickRequestSignal(ConnectionProtocolHandler *hdl) : Signal(hdl) {}

    virtual void fillData(Json::Value data);

    virtual void acceptDispatcher(MessageDispatcher &);

    virtual void serialize();

    const std::string &getNick() const;

private:
    std::string nick_;
    static Register<NickRequestSignal> reg;
};


#endif //ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
