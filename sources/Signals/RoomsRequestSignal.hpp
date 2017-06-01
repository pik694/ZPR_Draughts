//
// Created by Piotr Żelazko on 01.06.2017.
//

#ifndef ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP

#include "Signal.hpp"

class RoomsRequestSignal : public Signal{

    RoomsRequestSignal(ConnectionProtocolHandler*);

    virtual void fillData(Json::Value data){throw std::runtime_error("Not implemented yet");}

    virtual void acceptDispatcher(MessageDispatcher&);


};


#endif //ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP
