//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "PermissionSignal.hpp"
#include "MessageDispatcher.hpp"

const bool PermissionSignal::getGivenPermission() const {
    return givenPermission_;
}

void PermissionSignal::acceptDispatcher(MessageDispatcher &) {
    throw std::runtime_error("Dispatcher should not dispatch this kind of a signal");
}
