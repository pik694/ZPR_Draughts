//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP


#include "Signal.hpp"
#include <string>
#include "SignalFactory.hpp"
class EnterRoomSignal : public Signal{
public:
	EnterRoomSignal() {}
    EnterRoomSignal(ConnectionProtocolHandler* hdl, int roomID):Signal(hdl), roomID_(roomID){}

    virtual void acceptDispatcher(MessageDispatcher&);
    virtual void serialize();

    int getRoomID() const;

private:
   int roomID_;
   static Register<EnterRoomSignal> reg;
};


#endif //ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
