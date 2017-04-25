#include "Game.hpp"

void Game::addGameObserver(const GameObserver&) {
	throw std::runtime_error("Not implemented yet");
}

bool Game::StartGame() {
	throw std::runtime_error("Not implemented yet");

}

bool Game::makeMove(PlayerColour, std::vector<Point>) {
	throw std::runtime_error("Not implemented yet");

}
bool Game::makeMove(PlayerColour, Point, Point) {
	throw std::runtime_error("Not implemented yet");

}

Board Game::getGameboard() const {
	throw std::runtime_error("Not implemented yet");

}

const PieceKind Game::whoseTurn() const {
	throw std::runtime_error("Not implemented yet");

}