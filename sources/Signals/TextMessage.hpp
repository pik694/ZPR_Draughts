//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_TEXTMESSAGE_HPP
#define ZPR_DRAUGHTS_TEXTMESSAGE_HPP

#include <string>

#include "Signal.hpp"
#include "SignalFactory.hpp"

class Signal;

class TextMessage : public Signal {
public:
    TextMessage() {}

    TextMessage(ConnectionProtocolHandler *hdl, std::string message) : Signal(hdl), message_(message) {}

    virtual void acceptDispatcher(MessageDispatcher &);

    virtual void serialize();

    const std::string &getMessage() const;

private:
    std::string message_;
    static Register<TextMessage> reg;
};


#endif //ZPR_DRAUGHTS_TEXTMESSAGE_HPP
