//
// Created by Piotr Żelazko on 25.05.2017.
//

#include "GameLogic/PlayerColour.hpp"
#include "GameLogic/PieceKind.hpp"

std::ostream& operator<< (std::ostream& os, const PlayerColour& playerColour){

    os << static_cast<std::underlying_type<PlayerColour>::type> (playerColour);

    return os;
}

std::ostream& operator<< (std::ostream& os, const PieceKind& piece){

    os << static_cast<std::underlying_type<PieceKind>::type> (piece);

    return os;
}