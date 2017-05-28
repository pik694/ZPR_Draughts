//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_BOARDSIGNAL_HPP
#define ZPR_DRAUGHTS_BOARDSIGNAL_HPP


#include <GameLogic/Board.hpp>
#include "Signals/Signal.hpp"

class BoardSignal : public  Signal {
public:

    BoardSignal(Board board): board_(board){}

    const Board& getBoard() const {
        return board_;
    }

    void acceptDispatcher(MessageDispatcher dispatcher){
        throw std::runtime_error("Dispatcher should not dispatch this kind of signal");
    }

private:
    const Board board_;
};


#endif //ZPR_DRAUGHTS_BOARDSIGNAL_HPP
