//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_BOARDSIGNAL_HPP
#define ZPR_DRAUGHTS_BOARDSIGNAL_HPP


#include <GameLogic/Board.hpp>
#include "Signal.hpp"

class BoardSignal : public  Signal {
public:

    BoardSignal(ConnectionProtocolHandler* hdl, Board board):Signal(hdl),  board_(board){}

    const Board& getBoard() const;

    virtual void acceptDispatcher(MessageDispatcher&);

    virtual void serialize();

private:
    const Board board_;
};


#endif //ZPR_DRAUGHTS_BOARDSIGNAL_HPP
