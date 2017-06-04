//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_ENUMS_HPP
#define ZPR_DRAUGHTS_ENUMS_HPP


/*! \file
 * @brief An enumeration which represents all possible kinds of pieces in game (including none).
 *
 * \link PieceKind::none \endlink represents empty square.
 */
enum class PieceKind : uint8_t {
    none = 0,
    blackMen,
    whiteMen,
    blackKing,
    whiteKing,
};


#endif //ZPR_DRAUGHTS_ENUMS_HPP
