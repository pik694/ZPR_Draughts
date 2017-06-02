//
// Created by Piotr Żelazko on 29.05.2017.
//

#include "BoardSignal.hpp"

Register<BoardSignal> BoardSignal::reg("BoardSignal");

const Board &BoardSignal::getBoard() const {
    return board_;
}

void BoardSignal::acceptDispatcher(MessageDispatcher &) {
    throw std::runtime_error("Dispatcher should not dispatch this kind of a signal");
}

Json::Value BoardSignal::serialize() {
	Json::Value answer;
	Json::Value roomList;
    answer["type"] = "BoardSignal";

    answer["value"] = board_.toJSON();

    answer["move"] = isPlayersMove_;

    answer["team"] = team_;
    /*for(auto it=rooms_.begin();it!=rooms_.end();++it) {
    	roomList.append(std::to_string(*it));
    }*/

    //answer["value"] = roomList;

    return answer;
}

const bool BoardSignal::isPlayersMove() const {
    return isPlayersMove_;
}


