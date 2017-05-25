#include "Game.hpp"

void Game::addGameObserver(GameObserver* observer) {

	gameObservers_.push_back(observer);

}

void Game::startGame() {


	board_ = Board();
	currentTurn_ = PlayerColour::white;

	blackPieces_ = whitePieces_ = Board::BOARD_SIZE * Board::ROWS_OF_PIECES / 2;


}

bool Game::makeMove(PlayerColour player, const std::vector<Point>& points) {

    if (currentTurn_ != player || !validateMove(player, points))
        return false;

    movePiece(player, points);

    currentTurn_ = currentTurn_ == PlayerColour::white ? PlayerColour::black : PlayerColour ::black;
    return true;

}
bool Game::makeMove(PlayerColour player, Point begin, Point end) {

    return makeMove(player, {begin, end});

}

const Board& Game::getGameboard() const {

	return board_;

}

PlayerColour Game::whoseTurn() const {

	return currentTurn_;

}


///MARK: PRIVATE METHODS

bool Game::validatePoints(PieceKind piece, Point begin, Point end) {

	return !((begin.y_ >= Board::BOARD_SIZE || begin.y_ < 0)
		|| (begin.x_ >= Board::BOARD_SIZE || begin.x_ < 0)
		|| (end.y_ >= Board::BOARD_SIZE || end.y_ < 0)
		|| (end.x_ >= Board::BOARD_SIZE || end.x_ < 0)
		|| ((begin.x_ % 2 != begin.y_ % 2) || (end.x_ % 2 != end.y_ % 2))
		|| (piece == PieceKind::none)
		|| ((piece == PieceKind::whiteMen || piece == PieceKind::blackMen) && (begin.y_ < end.y_))
		|| (abs(begin.x_ - end.x_) != 1 || abs(begin.y_ - end.y_) != 1));
}


bool Game::validateMove(PlayerColour player, const std::vector<Point>& points) {

    Board tempBoard = board_;

    for (auto begin = points.begin(), end = begin + 1; end != points.end(); ++begin, ++end){


//tODO



    }


}

void Game::movePiece(PlayerColour player, const std::vector<Point>& points) {

    for (auto begin = points.begin(), end = begin + 1; end != points.end(); ++begin, ++end){

        PieceKind piece = board_.getPieceAt(*begin, player);

        board_.removePieceAt(*begin, player);

        int xDir = findDirection(end->x_, begin->x_);
        int yDir = findDirection(end->y_, begin->y_);

        board_.removePieceAt(Point(end->x_ + xDir, end->y_ + yDir), player);

        if (end->y_ == Board::BOARD_SIZE - 1) changeIntoAKing(piece);

        board_.setPieceAt(piece, *end, player);
    }
}


int Game::findDirection(int begin, int end){
    return end - begin < 0 ? -1 : 1;
}

void Game::changeIntoAKing(PieceKind& piece){
    switch (piece){
        case PieceKind::whiteMen:
            piece = PieceKind::whiteKing;
            break;
        case PieceKind::blackMen:
            piece = PieceKind::blackKing;
            break;
    }
}
