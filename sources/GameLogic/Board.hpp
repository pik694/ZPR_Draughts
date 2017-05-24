//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEBOARD_HPP
#define ZPR_DRAUGHTS_GAMEBOARD_HPP

#include <jsoncpp/json/json.h>
#include <algorithm>
#include <iostream>
#include <functional>
#include <stdexcept>

#include "PieceKind.hpp"
#include "Point.hpp"
#include "PlayerColour.hpp"


class Board {
public:

    using row_t = std::vector<PieceKind>;

    Board();
    Board(std::initializer_list<row_t>);



    const PieceKind& getPieceAt(const Point&, const PlayerColour& side = PlayerColour::white) const;

    void setPieceAt(const PieceKind& ,const Point&, const PlayerColour& side = PlayerColour::white);

    void removePieceAt(const Point&, const PlayerColour& side = PlayerColour::white);

    Json::Value toJSON();

private:
    PieceKind& pieceAt (const Point& point, const PlayerColour& side){
        return side == PlayerColour::white ?
                board_.at(point.y_).at(point.x_) : board_.at(BOARD_SIZE - point.y_ - 1).at(BOARD_SIZE - point.x_ - 1);
    }


    std::vector<row_t> board_;
    static size_t  BOARD_SIZE;
};


#endif //ZPR_DRAUGHTS_GAMEBOARD_HPP
