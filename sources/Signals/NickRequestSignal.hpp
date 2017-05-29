//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP

#include <string>
#include "Signals/Signal.hpp"

class NickRequestSignal : public Signal{
public:

    NickRequestSignal(std::string nick):nick_(nick){}

    const std::string& getNick() const;

    void acceptDispatcher(MessageDispatcher&);


private:
    const std::string nick_;
};


#endif //ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
