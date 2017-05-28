//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP


#include "Signals/Signal.hpp"

class NewRoomRequestSignal : public Signal{
public:

    NewRoomRequestSignal(std::string roomID): roomID_(roomID){}


    void acceptDispatcher(MessageDispatcher dispatcher);

    const std::string& getRoomID() const;

private:
    const std::string roomID_;
};


#endif //ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP
