//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP

#include <string>
#include "Signals/Signal.hpp"


class OpponentEnteredTheRoomSignal : public Signal {
public:

    OpponentEnteredTheRoomSignal (ConnectionProtocolHandler* hdl, std::string opponentNick):Signal(hdl), opponentNick_(opponentNick){}

    virtual void acceptDispatcher(MessageDispatcher&);

    virtual void serialize();

    const std::string& getOpponentNick() const;


private:
    std::string opponentNick_;
};


#endif //ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP
