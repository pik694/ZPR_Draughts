//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP


#include "Signals/Signal.hpp"

class NewRoomRequestSignal : public Signal{
public:

    NewRoomRequestSignal(std::string roomID): roomID_(roomID){}

    const std::string& getRoomID_() const {
        return roomID_;
    }

    void acceptDispatcher(MessageDispatcher dispatcher){
        dispatcher.visit(this);
    }

private:
    const std::string roomID_;
};


#endif //ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP
