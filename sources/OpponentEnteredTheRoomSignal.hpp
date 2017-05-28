//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP


#include "Signals/Signal.hpp"

class OpponentEnteredTheRoomSignal : public Signal {
public:

    OpponentEnteredTheRoomSignal (std::string opponentNick):opponentNick_(opponentNick){}

    void acceptDispatcher(MessageDispatcher dispatcher){
        throw std::runtime_error("Dispatcher should not dispatch this kind of signal");
    }

private:
    std::string opponentNick_;
};


#endif //ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP
