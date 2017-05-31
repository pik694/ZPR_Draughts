//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP


#include "Signal.hpp"
#include "SignalFactory.hpp"

class LeaveRoomSignal : public Signal {

public:
    LeaveRoomSignal() {}

    LeaveRoomSignal(ConnectionProtocolHandler *hdl) : Signal(hdl) {}

    virtual void acceptDispatcher(MessageDispatcher &);

    virtual void serialize();

private:
    static Register<LeaveRoomSignal> reg;
};


#endif //ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP
