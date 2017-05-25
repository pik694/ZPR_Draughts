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

    currentTurn_ = currentTurn_ == PlayerColour::white ? PlayerColour::black : PlayerColour ::white;
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
		|| ((piece == PieceKind::whiteMen || piece == PieceKind::blackMen) && (begin.y_ >= end.y_))
        || (abs(begin.x_ - end.x_) != abs(begin.y_ - end.y_))
        || ((piece == PieceKind::whiteMen || piece == PieceKind::blackMen) && abs(begin.x_ - end.x_) > 2));
}


bool Game::validateMove(PlayerColour player, const std::vector<Point>& points) {

    Board tempBoard = board_;

    bool captured = true;

    for (auto begin = points.begin(), end = begin + 1; end != points.end(); ++begin, ++end){

        if (!captured) return false;
        captured = false;


        PieceKind piece = board_.getPieceAt(*begin, player);
        tempBoard.removePieceAt(*begin, player);

        if (!validatePoints(piece, *begin, *end)
            || tempBoard.getPieceAt(*end, player) != PieceKind::none) return false;


        Point direction (findDirection(begin->x_, end->x_), findDirection(begin->y_, end->y_));


        if (*end - direction != *begin && tempBoard.getPieceAt(*end - direction, player) != PieceKind::none){
            PieceKind foundPiece = tempBoard.getPieceAt(*end - direction, player);
            switch (piece){
                case PieceKind::whiteMen:
                case PieceKind::whiteKing:
                    if (foundPiece != PieceKind::blackMen && foundPiece != PieceKind::blackKing)
                        return false;

                    tempBoard.removePieceAt(*end - direction, player);
                    captured = true;
                    break;

                case PieceKind::blackMen:
                case PieceKind::blackKing:
                    if (foundPiece != PieceKind::whiteMen && foundPiece != PieceKind::whiteKing)
                        return false;

                    tempBoard.removePieceAt(*end - direction, player);
                    captured = true;
                    break;

                default:
                    throw  std::runtime_error("Invalid piece" + std::to_string((uint8_t)piece));
            }

        }

        for (Point curr = *begin; curr != *end; curr += direction) {
            if (tempBoard.getPieceAt(curr, player) != PieceKind::none) return false;
        }

        if (!captured && (piece == PieceKind::whiteMen || piece == PieceKind::blackMen) && abs(begin->x_ - end->x_) > 1) return false;

        if (end->y_ == Board::BOARD_SIZE - 1) changeIntoAKing(piece);

        tempBoard.setPieceAt(piece, *end, player);

    }

    return (!captured && points.size() > 2) ? false : true;
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
        default:
            if (piece != PieceKind::blackKing && piece != PieceKind::whiteKing)
                    throw  std::runtime_error("Invalid pice" + std::to_string((uint8_t)piece));
            else break;
    }
}
