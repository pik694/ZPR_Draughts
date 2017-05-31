//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP


#include "Signals/Signal.hpp"
#include <string>
#include "SignalFactory.hpp"

class NewRoomRequestSignal : public Signal {
public:
    NewRoomRequestSignal() {}

    NewRoomRequestSignal(ConnectionProtocolHandler *hdl, std::string roomID) : Signal(hdl), roomID_(roomID) {}


    virtual void acceptDispatcher(MessageDispatcher &);

    virtual void serlialize();

    virtual void fillData(Json::Value data);

    const std::string &getRoomID() const;

private:
    std::string roomID_;
    static Register<NewRoomRequestSignal> reg;
};


#endif //ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP
