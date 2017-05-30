//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP


#include "Signal.hpp"
#include <string>

class EnterRoomSignal : public Signal{
public:

    EnterRoomSignal(std::string roomID): roomID_(roomID){}

    virtual void acceptDispatcher(MessageDispatcher&);

    const std::string& getRoomID() const;

private:
    const std::string roomID_;
};


#endif //ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
