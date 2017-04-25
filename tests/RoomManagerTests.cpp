#include <boost/test/unit_test.hpp>
#include <utility>
#include <string>
#include <iostream>
#include <RoomManager.hpp>
//#include Room.hpp"

BOOST_AUTO_TEST_SUITE(RoomManagerTests)
Room* addRoom();
	void deleteRoom(Room*);
	BOOST_AUTO_TEST_CASE(RoomAdd) {
		RoomManager *rooms = RoomManager::getInstance();
		Room* tmp = rooms->addRoom();
		BOOST_REQUIRE(rooms->deleteRoom(tmp));

		BOOST_REQUIRE(rooms->deleteRoom(nullptr) == false)
	}
BOOST_AUTO_TEST_SUITE_END()