#include "Game.hpp"

void Game::setGameObserver(GameObserver *observer) {

    gameObserver_ = observer;

}

void Game::startGame() {


    duringGame_ = true;
    board_ = Board();
    currentTurn_ = PlayerColour::white;

    blackPieces_ = whitePieces_ = Board::BOARD_SIZE * Board::ROWS_OF_PIECES / 2;


}

bool Game::makeMove(PlayerColour player, const std::vector<Point> &points) {

    if (!duringGame_) return false;

    if (currentTurn_ != player || !validateMove(player, points))
        return false;

    movePiece(player, points);

    currentTurn_ = currentTurn_ == PlayerColour::white ? PlayerColour::black : PlayerColour::white;
    return true;

}

bool Game::makeMove(PlayerColour player, Point begin, Point end) {

    return makeMove(player, {begin, end});

}

Board Game::getBoard(PlayerColour playerColour) const {

    if (playerColour == PlayerColour::white) return board_;

    Board board;

    for(int i = 0; i < Board::BOARD_SIZE; ++i){
        for (int j = 0; j < Board::BOARD_SIZE / 2; ++j) {
            Point point (i, 2*j + (i % 2));
            board.setPieceAt(board_.getPieceAt(point, PlayerColour::black), point, PlayerColour::white);
        }
    }

    return board;

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


bool Game::validateMove(PlayerColour player, const std::vector<Point> &points) {

    //TODO: refactor

    Board tempBoard = board_;

    bool captured = true;

    for (auto begin = points.begin(), end = begin + 1; end != points.end(); ++begin, ++end) {

        if (!captured) return false;
        captured = false;


        PieceKind piece = tempBoard.getPieceAt(*begin, player);

        if ((player == PlayerColour::white && piece != PieceKind::whiteKing && piece != PieceKind::whiteMen)
            || (player == PlayerColour::black && piece != PieceKind::blackKing && piece != PieceKind::blackMen))
            return false;

        tempBoard.removePieceAt(*begin, player);

        if (!validatePoints(piece, *begin, *end)
            || tempBoard.getPieceAt(*end, player) != PieceKind::none)
            return false;


        Point direction(findDirection(begin->x_, end->x_), findDirection(begin->y_, end->y_));


        if (*end - direction != *begin && tempBoard.getPieceAt(*end - direction, player) != PieceKind::none) {
            PieceKind foundPiece = tempBoard.getPieceAt(*end - direction, player);
            switch (piece) {
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
                    throw std::runtime_error("Invalid piece" + std::to_string((uint8_t) piece));
            }

        }

        for (Point curr = *begin; curr != *end; curr += direction) {
            if (tempBoard.getPieceAt(curr, player) != PieceKind::none) return false;
        }

        if (!captured && (piece == PieceKind::whiteMen || piece == PieceKind::blackMen) &&
            abs(begin->x_ - end->x_) > 1)
            return false;

        if (end->y_ == Board::BOARD_SIZE - 1) changeIntoAKing(piece);

        tempBoard.setPieceAt(piece, *end, player);


    }

    return !(!captured && points.size() > 2);
}

void Game::movePiece(PlayerColour player, const std::vector<Point> &points) {

    for (auto begin = points.begin(), end = begin + 1; end != points.end(); ++begin, ++end) {

        PieceKind piece = board_.getPieceAt(*begin, player);

        board_.removePieceAt(*begin, player);

        Point direction(findDirection(end->x_, begin->x_), findDirection(end->y_, begin->y_));

        if (board_.getPieceAt(Point(end->x_, end->y_) + direction, player) != PieceKind::none) {

            int &count = player == PlayerColour::white ? (blackPieces_) : (whitePieces_);

            if (--count == 0) {
                gameObserver_->playerWon(player);
                duringGame_ = false;
            }
        }

        board_.removePieceAt(Point(end->x_, end->y_) + direction, player);

        if (end->y_ == Board::BOARD_SIZE - 1) changeIntoAKing(piece);

        board_.setPieceAt(piece, *end, player);
    }


}


int Game::findDirection(int begin, int end) {
    return end - begin < 0 ? -1 : 1;
}

void Game::changeIntoAKing(PieceKind &piece) {
    switch (piece) {
        case PieceKind::whiteMen:
            piece = PieceKind::whiteKing;
            break;
        case PieceKind::blackMen:
            piece = PieceKind::blackKing;
            break;
        default:
            if (piece != PieceKind::blackKing && piece != PieceKind::whiteKing)
                throw std::runtime_error("Invalid piece" + std::to_string((uint8_t) piece));
            else break;
    }
}
