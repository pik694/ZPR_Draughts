//
// Created by Piotr Żelazko on 31.05.2017.
//

#ifndef ZPR_DRAUGHTS_MOVESIGNAL_HPP
#define ZPR_DRAUGHTS_MOVESIGNAL_HPP

#include <vector>

#include <GameLogic/Point.hpp>
#include "Signal.hpp"


class MoveSignal : public Signal {
public:
    MoveSignal(std::initializer_list<Point> path, ConnectionProtocolHandler *hdl) :
            Signal(hdl),
            move_(path) {}

    const std::vector<Point> &getMove() const;

    virtual void fillData(Json::Value);

    virtual Json::Value serialize();

    virtual void acceptDispatcher(MessageDispatcher &);

    const std::vector<Point> move_;
};


#endif //ZPR_DRAUGHTS_MOVESIGNAL_HPP
