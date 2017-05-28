#include "Server.hpp"

#include <iostream>

using namespace websocketpp;
using namespace std;


int main()
{
	std::cout << "Server starting ... \n"<<std::endl;
	try {
		Server myServer;
		myServer.run(9002);
	}
	catch(websocketpp::exception const & e) {
		std::cout<<e.what()<<std::endl;
	}
}