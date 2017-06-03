#include "Server.hpp"

using namespace websocketpp;
using namespace std;


//TODO: namespaces
//TODO: shered_ptr -> weak_ptr<Room> in Player

int main() {

    std::cout << "Server starting ... \n" << std::endl;
    try {
        Server::getInstance()->run(9002);
    }
    catch (websocketpp::exception const &e) {
        std::cout << e.what() << std::endl;
    }
    /*Game game(std::move(Board(
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


    game.makeMove(PlayerColour::white, {Point(0,0), Point(2,2), Point(4,4), Point(2, 6)});*/


}