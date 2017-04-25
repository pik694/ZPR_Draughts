//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEBOARD_HPP
#define ZPR_DRAUGHTS_GAMEBOARD_HPP

#include <jsoncpp/json/json.h>

#include "PieceKind.hpp"
#include "Point.hpp"
#include "PlayerColour.hpp"

class Board {
public:

    using row = std::vector<PieceKind>;

    Board();
    Board(std::initializer_list<row>);

    PieceKind getPieceAt(Point, PlayerColour side = PlayerColour::white) const;
    void setPieceAt(PieceKind, Point);

    void remocePieceAt(Point);

    Json::Value toJSON();
};


#endif //ZPR_DRAUGHTS_GAMEBOARD_HPP
