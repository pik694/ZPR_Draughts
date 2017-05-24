//
// Created by Piotr Żelazko on 23.04.2017.
//

#include "Board.hpp"


size_t Board::BOARD_SIZE = 8;

using namespace std::placeholders;


Board::Board(): board_ (BOARD_SIZE, row_t (BOARD_SIZE, PieceKind::none)) {

	for (int column = 0; column < BOARD_SIZE; column++){
		for (int row = 0; row <  3; row++){ // 3 rows of pieces for each player
			if (row % 2 == column % 2){
				board_.at(row).at(column) = PieceKind::whiteMen;
			}
			else {
				board_.at(BOARD_SIZE - row - 1).at(column) = PieceKind ::blackMen;
			}
		}
	}
}
Board::Board(std::initializer_list<row_t> list):board_(){


    if (list.size() != BOARD_SIZE)
        throw std::invalid_argument ("Invalid column size in board. "
                                             "Got : " +  std::to_string(list.size()) +
                                             ", but expected : " + std::to_string(BOARD_SIZE));

    std::for_each(list.begin(), list.end(),
                  [&](row_t row){
                      if (row.size() != BOARD_SIZE)
                          throw std::invalid_argument ("Invalid row size in board. "
                                                               "Got : " +  std::to_string(row.size()) +
                                                               ", but expected : " + std::to_string(BOARD_SIZE));
                      this->board_.push_back(row);
                  });

}

const PieceKind& Board::getPieceAt(const Point& point, const PlayerColour& side) const {

    return side == PlayerColour::white ?
           board_.at(point.y_).at(point.x_) : board_.at(BOARD_SIZE - point.y_ - 1).at(BOARD_SIZE - point.x_ - 1);

}
void Board::setPieceAt(const PieceKind& piece, const Point& point, const PlayerColour& side) {

    pieceAt(point, side) = piece;
}

void Board::removePieceAt(const Point& point, const PlayerColour& side) {

    pieceAt(point, side) = PieceKind::none;

}



Json::Value Board::toJSON() {
	throw std::runtime_error("Not implemented yet");
}