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



    void addGameObserver(const GameObserver&);

    bool StartGame();

    bool makeMove(const Player&, std::vector<Point>);
    bool makeMove(const Player&, Point, Point);

    const Gameboard&  getGameboard() const;

    bool isPlayersTurn(const Player&);

private:



	// collection storing game data
};
#endif // GAME_HPP