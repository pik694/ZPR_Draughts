//
// Created by Piotr Żelazko on 01.06.2017.
//

#ifndef ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP

#include "Signal.hpp"
#include "SignalFactory.hpp"
class RoomsRequestSignal : public Signal{
public:
	RoomsRequestSignal() {}
    RoomsRequestSignal(ConnectionProtocolHandler*);

    virtual void fillData(Json::Value data);

    virtual void acceptDispatcher(MessageDispatcher&);

    static Register<RoomsRequestSignal> reg;

};


#endif //ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP
