//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "TextMessage.hpp"

void TextMessage::acceptDispatcher(MessageDispatcher dispatcher){
    dispatcher.visit(*this);
}

const std::string& TextMessage::getMessage() const {
    return message_;
}