//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
#define ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP


#include "Signals/Signal.hpp"

class PermissionSignal : public Signal{


public:
    PermissionSignal(bool givenPermission): givenPermission_(givenPermission){}

    const bool getGivenPermission() const {
        return givenPermission_;
    }

    void acceptDispatcher(MessageDispatcher dispatcher){
        throw std::runtime_error("Dispatcher should not dispatch this kind of signal");
    }

private:
    const bool givenPermission_;
};


#endif //ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
