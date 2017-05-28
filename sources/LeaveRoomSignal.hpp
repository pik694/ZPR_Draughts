//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP


#include "Signals/Signal.hpp"

class LeaveRoomSignal : public Signal{
public:
    void acceptDispatcher(MessageDispatcher dispatcher){
        dispatcher.visit(this);
    }

};


#endif //ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP
