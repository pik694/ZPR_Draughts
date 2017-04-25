//
// Created by Piotr Żelazko on 23.04.2017.
//

#include "Board.hpp"
using row = std::vector<PieceKind>;

Board::Board() {
	throw std::runtime_error("Not implemented yet");
}
Board::Board(std::initializer_list<row>) {
	throw std::runtime_error("Not implemented yet");

}

PieceKind Board::getPieceAt(Point, PlayerColour side) const {
	throw std::runtime_error("Not implemented yet");

}
void Board::setPieceAt(PieceKind, Point) {
	throw std::runtime_error("Not implemented yet");

}

void Board::remocePieceAt(Point) {
	throw std::runtime_error("Not implemented yet");

}

Json::Value Board::toJSON() {
	throw std::runtime_error("Not implemented yet");

}