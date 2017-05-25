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
                        {PieceKind::blackMen,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::whiteMen,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::whiteMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                }
        )));

        game.makeMove(PlayerColour::white, Point(0, 0), Point(1, 1));
        game.makeMove(PlayerColour::black, Point(7, 1), Point(5, 3));

        bool a =game.getGameboard().getPieceAt(Point(7, 1), PlayerColour::black) == PieceKind::none;
        a=game.getGameboard().getPieceAt(Point(6, 2), PlayerColour::black) == PieceKind::none;
        a=game.getGameboard().getPieceAt(Point(5, 3), PlayerColour::black) == PieceKind::blackMen;

;

}