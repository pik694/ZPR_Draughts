//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEBOARD_HPP
#define ZPR_DRAUGHTS_GAMEBOARD_HPP

#include <jsoncpp/json/json.h>

#include "PieceKind.hpp"
#include "Point.hpp"

class Board {
public:

    using row = std::vector<PieceKind>;

    Board();
    Board(std::initializer_list<row>);

    PieceKind getPieceAt(Point);
    void setPieceAt(PieceKind, Point);

    void remocePieceAt(Point);

    Json::Value toJSON();
};


#endif //ZPR_DRAUGHTS_GAMEBOARD_HPP
