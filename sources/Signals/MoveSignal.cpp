//
// Created by Piotr Żelazko on 31.05.2017.
//

#include "MoveSignal.hpp"

Register<MoveSignal> MoveSignal::reg("MoveSignal");

const std::vector<Point> &MoveSignal::getMove() const {
    return move_;
}

void MoveSignal::fillData(Json::Value val) {
	
    std::cout<<"val size"<<val.size()<<std::endl;
    //move_.push_back(Point(val["value"][0].asInt(),val["value"][1].asInt()));
    //move_.push_back(Point(val["value"][2].asInt(),val["value"][3].asInt()));

    for(int i=0;i<val["value"].size();i+=2) {
    	move_.push_back(Point(val["value"][i].asInt(),val["value"][i+1].asInt()));
    }

}

Json::Value MoveSignal::serialize() {
    throw std::runtime_error("Not implemented yet");
}


void MoveSignal::acceptDispatcher(MessageDispatcher &dispatcher) {
    dispatcher.dispatch(*this);
}
