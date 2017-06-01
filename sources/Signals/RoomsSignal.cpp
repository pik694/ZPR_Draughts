//
// Created by Piotr Żelazko on 01.06.2017.
//

#include <forward_list>
#include "RoomsSignal.hpp"


RoomsSignal::RoomsSignal(ConnectionProtocolHandler* hdl, const std::vector<int>& rooms): Signal(hdl), rooms_(rooms){}

const std::vector<int> &RoomsSignal::getRooms() {
    return rooms_;
}
