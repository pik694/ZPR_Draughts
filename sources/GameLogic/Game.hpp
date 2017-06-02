#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include <memory>

#include "PlayerColour.hpp"
#include "Board.hpp"
#include "GameObserver.hpp"
#include "PieceKind.hpp"
#include "Point.hpp"


class Game {
public:

    Game() : gameObserver_(nullptr) {
        startGame();
    }

    Game(Board &&board) : board_(board), gameObserver_(nullptr) {


        currentTurn_ = PlayerColour::white;

        blackPieces_ = whitePieces_ = 0;

        for (int i = 0; i < Board::BOARD_SIZE; ++i){
            for (int j = 0; j < Board::BOARD_SIZE; ++j) {
                PieceKind currPiece = board_.getPieceAt(Point(i, j), PlayerColour::white);

                if (currPiece == PieceKind::whiteMen || currPiece == PieceKind::whiteKing){
                    ++whitePieces_;
                }
                else if (currPiece == PieceKind::blackMen || currPiece == PieceKind::blackKing){
                    ++blackPieces_;
                }

            }
        }

        duringGame_ = true;

    }

    void setGameObserver(GameObserver*);

    void startGame();

    bool makeMove(PlayerColour, const std::vector<Point> &);

    bool makeMove(PlayerColour, Point, Point);

    Board getBoard(PlayerColour) const;

    PlayerColour whoseTurn() const;

private:

    bool validatePoints(PieceKind, Point begin, Point end);

    bool validateMove(PlayerColour, const std::vector<Point> &);

    void movePiece(PlayerColour, const std::vector<Point> &);

    int findDirection(int begin, int end);

    void changeIntoAKing(PieceKind &);

    Board board_;
    PlayerColour currentTurn_;

    bool duringGame_;

    int whitePieces_;
    int blackPieces_;

    GameObserver* gameObserver_;

};

#endif // GAME_HPP