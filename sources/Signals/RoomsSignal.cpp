//
// Created by Piotr Żelazko on 01.06.2017.
//

#include <forward_list>
#include "RoomsSignal.hpp"
#include <string>
RoomsSignal::RoomsSignal(ConnectionProtocolHandler* hdl, const std::vector<int>& rooms,std::string action): Signal(hdl), rooms_(rooms),action_(action){}

const std::vector<int> &RoomsSignal::getRooms() {
    return rooms_;
}

Json::Value RoomsSignal::serialize() {
	Json::Value answer;
	Json::Value roomList;
    answer["type"] = action_;


    for(auto it=rooms_.begin();it!=rooms_.end();++it) {
    	roomList.append(std::to_string(*it));
    }

    answer["value"] = roomList;

    return answer;
}