//
// Created by Piotr Żelazko on 01.06.2017.
//

#ifndef ZPR_DRAUGHTS_ROOMSSIGNAL_HPP
#define ZPR_DRAUGHTS_ROOMSSIGNAL_HPP


#include "Signal.hpp"

class RoomsSignal : public Signal{

public:

    RoomsSignal(ConnectionProtocolHandler*, const std::vector<int>&);

    virtual void acceptDispatcher(MessageDispatcher&){};

    virtual void fillData(Json::Value data){throw std::runtime_error("Not implemented yet");}

    const std::vector<int>& getRooms();

private:

    const std::vector<int> rooms_;

};


#endif //ZPR_DRAUGHTS_ROOMSSIGNAL_HPP
