#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Player.hpp"
#include "Point.hpp"
#include <PieceKind.hpp>
#include "GameObserver.hpp"
#include "Board.hpp"
#include "PlayerColour.hpp"

class Game
{
public:

    Game();
    Game(Board&& board):gameboard_(board){
    }

    void addGameObserver(const GameObserver&);

    bool StartGame();

    bool makeMove(PlayerColour, std::vector<Point>);
    bool makeMove(PlayerColour, Point, Point);

    Board  getGameboard() const;

    const PieceKind whoseTurn() const;

private:

    Board gameboard_;

};
#endif // GAME_HPP