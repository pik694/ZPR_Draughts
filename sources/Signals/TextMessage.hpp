//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_TEXTMESSAGE_HPP
#define ZPR_DRAUGHTS_TEXTMESSAGE_HPP

#include <string>

#include "Signal.hpp"

class Signal;

class TextMessage : public Signal {
public:

    TextMessage(std::string message):message_(message){}

    void acceptDispatcher(MessageDispatcher&);

    const std::string& getMessage() const;

private:
    std::string message_;
};


#endif //ZPR_DRAUGHTS_TEXTMESSAGE_HPP
