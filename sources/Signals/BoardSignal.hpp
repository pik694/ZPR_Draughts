//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_BOARDSIGNAL_HPP
#define ZPR_DRAUGHTS_BOARDSIGNAL_HPP


#include <GameLogic/Board.hpp>
#include "Signal.hpp"
#include "SignalFactory.hpp"

class BoardSignal : public  Signal {
public:
	BoardSignal(): isPlayersMove_(false) {} //TODO: remove this constructor
    BoardSignal(ConnectionProtocolHandler* hdl, Board board, bool isPlayersMove):Signal(hdl),  board_(board), isPlayersMove_(isPlayersMove){}

    const Board& getBoard() const;

	const bool isPlayersMove() const;

	virtual void acceptDispatcher(MessageDispatcher&);
    virtual void serialize();

private:
    const Board board_;
	const bool isPlayersMove_;
    static Register<BoardSignal> reg;
};


#endif //ZPR_DRAUGHTS_BOARDSIGNAL_HPP
