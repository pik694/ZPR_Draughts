#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

#include "Player.hpp"
#include "Point.hpp"
#include <GameLogic/PieceKind.hpp>
#include "GameObserver.hpp"
#include "Board.hpp"
#include "PlayerColour.hpp"

class Game
{
public:

    Game(): gameObservers_(){
        startGame();
    }

    Game(Board&& board):board_(board), gameObservers_() {

        currentTurn_ = PlayerColour::white;
        blackPieces_ = whitePieces_ = Board::BOARD_SIZE * Board::ROWS_OF_PIECES / 2;

    }

    void addGameObserver(GameObserver*);

    void startGame();

    bool makeMove(PlayerColour, const std::vector<Point>&);
    bool makeMove(PlayerColour, Point, Point);

    const Board&  getBoard() const;

    PlayerColour whoseTurn() const;

private:

    bool validatePoints(PieceKind , Point begin, Point end);
    bool validateMove(PlayerColour , const std::vector<Point>&);
    void movePiece(PlayerColour , const std::vector<Point>&);
    int findDirection(int begin, int end);
    void changeIntoAKing(PieceKind&);

    Board board_;
    PlayerColour currentTurn_;

    int whitePieces_;
    int blackPieces_;

    std::vector<GameObserver*> gameObservers_;

};
#endif // GAME_HPP