//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "PermissionSignal.hpp"

Register<PermissionSignal> PermissionSignal::reg("PermissionSignal");


void PermissionSignal::acceptDispatcher(MessageDispatcher &) {
    throw std::runtime_error("Dispatcher should not dispatch this kind of a signal");
}

Json::Value PermissionSignal::serialize() {
    Json::Value answer;
    answer["type"] = action_;
    answer["value"] = givenPermission_;
    return answer;
}
