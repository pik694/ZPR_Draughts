//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEBOARD_HPP
#define ZPR_DRAUGHTS_GAMEBOARD_HPP

#include <jsoncpp/json/json.h>

#include "Pawn.hpp"
#include "Point.hpp"

class Gameboard {
public:

    Pawn getPawnAt(Point);
    void setPawnAt(Pawn, Point);

    void removePawnAt(Point);

    Json::Value toJSON();
};


#endif //ZPR_DRAUGHTS_GAMEBOARD_HPP
