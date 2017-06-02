//
// Created by Piotr Żelazko on 23.04.2017.
//

#include "Board.hpp"

size_t Board::BOARD_SIZE = 8;
size_t Board::ROWS_OF_PIECES = 3;

using namespace std::placeholders;


Board::Board() : board_(BOARD_SIZE, row_t(BOARD_SIZE, PieceKind::none)) {

    for (int column = 0; column < BOARD_SIZE; column++) {
        for (int row = 0; row < ROWS_OF_PIECES; row++) {
            if (row % 2 == column % 2) {
                board_.at(row).at(column) = PieceKind::whiteMen;
            } else {
                board_.at(BOARD_SIZE - row - 1).at(column) = PieceKind::blackMen;
            }
        }
    }
}

Board::Board(std::initializer_list<row_t> list) : board_() {


    if (list.size() != BOARD_SIZE)
        throw std::invalid_argument("Invalid column size in board_. "
                                            "Got : " + std::to_string(list.size()) +
                                    ", but expected : " + std::to_string(BOARD_SIZE));


    for (auto row = list.end(); row != list.begin();) {

        --row;

        if (row->size() != BOARD_SIZE)
            throw std::invalid_argument("Invalid row size in board_. "
                                                "Got : " + std::to_string(row->size()) +
                                        ", but expected : " + std::to_string(BOARD_SIZE));
        this->board_.push_back(*row);
    }

}

PieceKind Board::getPieceAt(Point point, PlayerColour side) const {

    return side == PlayerColour::white ?
           board_.at(point.y_).at(point.x_) : board_.at(BOARD_SIZE - point.y_ - 1).at(BOARD_SIZE - point.x_ - 1);

}

void Board::setPieceAt(PieceKind piece, Point point, PlayerColour side) {

    if (point.x_ % 2 != point.y_ % 2)
        throw std::invalid_argument("Points parity does not match. "
                                            "x:" + std::to_string(point.x_) +
                                    " y:" + std::to_string(point.y_));

    pieceAt(point, side) = piece;
}

void Board::removePieceAt(Point point, PlayerColour side) {

    pieceAt(point, side) = PieceKind::none;

}


Json::Value Board::serialize() const {
    Json::Value boardList;
    for(int i=0;i<BOARD_SIZE;++i) {
        for(int j=0;j<BOARD_SIZE;++j) {
            boardList.append((int)board_[i][j]);
        }
    }
    return boardList;
}