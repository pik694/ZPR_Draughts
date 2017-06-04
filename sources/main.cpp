#include "Server.hpp"

using namespace websocketpp;
using namespace std;



//TODO: namespaces


#include "Player.hpp"
#include "Room.hpp"

#include "../tests/Helpers/TestSignalSendDelegate.hpp"
#include "../tests/Helpers/TestConnectionProtocolHandler.hpp"


int main() {

    std::cout << "Server starting ... \n" << std::endl;
    try {
        Server::getInstance()->run(9002);
    }
    catch (websocketpp::exception const &e) {
        std::cout << e.what() << std::endl;
    }


}