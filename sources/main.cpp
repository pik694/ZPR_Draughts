#include "Server.hpp"

#include <iostream>
#include "GameLogic/Board.hpp"

using namespace websocketpp;
using namespace std;


int main()
{

    Game game(std::move(Board(
            {
                    {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    {PieceKind::whiteMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
            }
    )));


    game.makeMove(PlayerColour::white, {Point(0,0), Point(2,2), Point(4,4), Point(2, 6)});

}