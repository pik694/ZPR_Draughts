//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP


#include "Signal.hpp"

class LeaveRoomSignal : public Signal{

public:

    virtual void acceptDispatcher(MessageDispatcher&);

};


#endif //ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP
