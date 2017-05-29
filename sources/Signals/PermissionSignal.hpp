//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
#define ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP

#include <string>
#include "Signals/Signal.hpp"


class PermissionSignal : public Signal{


public:
    PermissionSignal(bool givenPermission): givenPermission_(givenPermission){}

    const bool getGivenPermission() const;

    void acceptDispatcher(MessageDispatcher&);

private:
    const bool givenPermission_;
};


#endif //ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
