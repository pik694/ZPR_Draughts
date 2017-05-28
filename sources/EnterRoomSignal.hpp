//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP


#include "Signals/Signal.hpp"

class EnterRoomSignal : public Signal{
public:
    EnterRoomSignal(std::string roomID): roomID_(roomID){}

    virtual void acceptDispatcher(MessageDispatcher dispatcher){
        dispatcher.visit(this);
    }

    const std::string& getRoomID() const {
        return roomID_;
    }

private:
    const std::string roomID_;
};


#endif //ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
