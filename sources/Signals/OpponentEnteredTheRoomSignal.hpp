//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP

#include <string>
#include "Signals/Signal.hpp"
#include "SignalFactory.hpp"

class OpponentEnteredTheRoomSignal : public Signal {
public:
    OpponentEnteredTheRoomSignal() {}

    OpponentEnteredTheRoomSignal(ConnectionProtocolHandler *hdl, std::string opponentNick) : Signal(hdl), opponentNick_(
            opponentNick) {}

    virtual void acceptDispatcher(MessageDispatcher &);

    virtual Json::Value serialize();

    const std::string &getOpponentNick() const;

    static Register<OpponentEnteredTheRoomSignal> reg;
private:
    std::string opponentNick_;
};


#endif //ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP
