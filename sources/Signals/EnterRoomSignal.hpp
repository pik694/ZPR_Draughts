//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP


#include "Signal.hpp"
#include <string>

class EnterRoomSignal : public Signal{
public:

    EnterRoomSignal(ConnectionProtocolHandler* hdl, int roomID):Signal(hdl), roomID_(roomID){}

    virtual void acceptDispatcher(MessageDispatcher&);
    virtual void serialize();

    int getRoomID() const;

private:
   int roomID_;
};


#endif //ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
