#include "Server.hpp"

using namespace websocketpp;
using namespace std;



//TODO: namespaces


#include "Player.hpp"
#include "Room.hpp"

#include "../tests/Helpers/TestSignalSendDelegate.hpp"
#include "../tests/Helpers/TestConnectionProtocolHandler.hpp"


int main() {

//    std::cout << "Server starting ... \n" << std::endl;
//    try {
//        Server::getInstance()->run(9002);
//    }
//    catch (websocketpp::exception const &e) {
//        std::cout << e.what() << std::endl;
//    }



    std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
    TestConnectionProtocolHandler* protocolHandler = new TestConnectionProtocolHandler();

    std::shared_ptr<Player> player1 (new Player("player_one", protocolHandler, delegateOne));

    std::shared_ptr<Room> room (new Room(0));

    room->joinRoom(player1);

    room->makeMove({{2,0},{3,1}}, player1);

    room->startNewGame();
    room->makeMove({{2,0},{3,1}}, player1);

    delegateOne->getSignal();


}