//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
#define ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP

#include <string>
#include "Signals/Signal.hpp"
#include "SignalFactory.hpp"

class PermissionSignal : public Signal {


public:
    PermissionSignal() : givenPermission_(false) {}

    PermissionSignal(ConnectionProtocolHandler *hdl, bool givenPermission) : Signal(hdl),
                                                                             givenPermission_(givenPermission) {}

    const bool getGivenPermission() const;

    virtual void acceptDispatcher(MessageDispatcher &);

    virtual void fillData(Json::Value) {};

    virtual void serialize();

private:
    const bool givenPermission_;
    static Register<PermissionSignal> reg;
};


#endif //ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
