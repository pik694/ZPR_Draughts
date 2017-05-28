//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_TEXTMESSAGE_HPP
#define ZPR_DRAUGHTS_TEXTMESSAGE_HPP

#include <string>
#include "Signals/Signal.hpp"

class TextMessage : public Signal {
public:

    TextMessage(std::string message):message_(message){}

    void acceptDispatcher(MessageDispatcher dispatcher){
        dispatcher.visit(this);
    }

    const std::string& getMessage() const {
        return message_;
    }

private:
    std::string message_;
};


#endif //ZPR_DRAUGHTS_TEXTMESSAGE_HPP
