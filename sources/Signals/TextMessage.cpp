//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "TextMessage.hpp"
#include <MessageDispatcher.hpp>

Register<TextMessage> TextMessage::reg("TextMessage");

void TextMessage::acceptDispatcher(MessageDispatcher &dispatcher) {
    dispatcher.dispatch(*this);
}

const std::string &TextMessage::getMessage() const {
    return message_;
}

Json::Value TextMessage::serialize() {
    Json::Value answer;
    answer["type"] = "TextMessage";
    answer["value"] = message_;
    return answer;
}

void TextMessage::fillData(Json::Value data) {
    message_ = data.get("value", "").asString();
}