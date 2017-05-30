//
// Created by Piotr Żelazko on 29.05.2017.
//

#include <MessageDispatcher.hpp>
#include "TextMessage.hpp"

void TextMessage::acceptDispatcher(MessageDispatcher& dispatcher){
    dispatcher.dispatch(*this);
}

const std::string& TextMessage::getMessage() const {
    return message_;
}

void TextMessage::serialize() {
    throw std::runtime_error("Not implemented yet");
}
