#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Player.hpp"
#include "Point.hpp"
#include "GameObserver.hpp"
#include "Gameboard.hpp"

class Game
{
public:

    Game(const Player* whitePlayer, const Player* blackPlayer);

    void addGameObserver(const GameObserver&);

    bool StartGame();

    bool makeMove(const Player*, std::vector<Point>);
    bool makeMove(const Player*, Point, Point);

    const Gameboard&  getGameboard() const;

    const Player* whoseTurn() const;

private:

    Gameboard gameboard_;

};
#endif // GAME_HPP