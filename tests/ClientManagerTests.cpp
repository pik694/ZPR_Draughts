#include <boost/test/unit_test.hpp>
#include <utility>
#include <string>
#include <iostream>
#include "../sources/ClientManager.hpp"
BOOST_AUTO_TEST_SUITE(ClientManagerTests)

	BOOST_AUTO_TEST_CASE(ClientAdd) {
		ClientManager* clients = ClientManager::getInstance();
		clients->addNewPlayer("abc");
		BOOST_CHECK(clients->addNewPlayer("abc"));
	}

BOOST_AUTO_TEST_SUITE_END()