//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
#define ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP

#include <string>
#include "Signal.hpp"
#include "SignalFactory.hpp"

class PermissionSignal : public Signal {


public:
    PermissionSignal() : givenPermission_(false) {}

    PermissionSignal(ConnectionProtocolHandler *hdl, bool givenPermission,std::string action="") : Signal(hdl),
                                                                             givenPermission_(givenPermission),action_(action) {}

    const bool getGivenPermission() const;

    virtual void acceptDispatcher(MessageDispatcher &);

    virtual void fillData(Json::Value) {};

    virtual Json::Value serialize();

private:
    const bool givenPermission_;
    std::string action_;
    static Register<PermissionSignal> reg;
};


#endif //ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
