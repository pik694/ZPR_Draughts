//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_BOARD_HPP
#define ZPR_DRAUGHTS_BOARD_HPP

/*! @file
 *  @brief Class Board represents a board used in draughts. Defines board size and provides the interface that is sufficient to play a game.
 */

#include <jsoncpp/json/json.h>
#include <algorithm>
#include <string>
#include <functional>
#include <stdexcept>

#include "PieceKind.hpp"
#include "Point.hpp"
#include "PlayerColour.hpp"



/*!
 * @brief Class Board represents a board used in draughts. Defines board size and provides the interface that is sufficient to play a game.
 */
class Board {
public:
    using row_t = std::vector<PieceKind>;


    /*!
     * @brief Default constructor.
     */
    Board();

    /*!
     * Constructor used in  testing.
     *
     * Enables to provide initial state of the board.
     * @param list List of vectors<row_t> based on which the board is created.
     */
    Board(std::initializer_list<row_t> list);


    /*!
     * Returns @link PieceKind @endlink which stays on the square described by the given @link Point @endlink
     * @param point describes the square to check
     * @param side specifies how to translate given coordinates.
     * @return piece standing at given point.
     */
    PieceKind getPieceAt(Point point, PlayerColour side) const;

    /*!
     * Sets given @link PieceKind @endlink on the given square of the board.
     * @param piece specifies @link PieceKind @endlink which should be put on the given square.
     * @param point describes the square on which given piece should be put.
     * @param side specifies how to translate given coordinates.
     */
    void setPieceAt(PieceKind piece, Point point, PlayerColour side);

    /*!
     * Removes any piece from the given square - sets it to @link PieceKind::none @endlink
     * @param point describes the square to check
     * @param side specifies how to translate given coordinates.
     */
    void removePieceAt(Point point, PlayerColour side);

    /*!
     * Serializes the instance of Board. Useful when sending the whole board through the Internet
     * @return Json::Value ready to be sent.
     */
    Json::Value serialize() const;

    static size_t BOARD_SIZE; ///!< Specifies board size
    static size_t ROWS_OF_PIECES; ///!< Specifies with how many rows of pieces per player the game should be started.

private:

    PieceKind &pieceAt(const Point &point, const PlayerColour &side) {
        return side == PlayerColour::white ?
               board_.at(point.y_).at(point.x_) : board_.at(BOARD_SIZE - point.y_ - 1).at(BOARD_SIZE - point.x_ - 1);
    }


    std::vector<row_t> board_;
};


#endif //ZPR_DRAUGHTS_BOARD_HPP
