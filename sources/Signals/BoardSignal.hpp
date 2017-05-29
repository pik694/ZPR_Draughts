//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_BOARDSIGNAL_HPP
#define ZPR_DRAUGHTS_BOARDSIGNAL_HPP


#include <GameLogic/Board.hpp>
#include "Signal.hpp"

class BoardSignal : public  Signal {
public:

    BoardSignal(Board board): board_(board){}

    const Board& getBoard() const;

    virtual void acceptDispatcher(MessageDispatcher&);


private:
    const Board board_;
};


#endif //ZPR_DRAUGHTS_BOARDSIGNAL_HPP
