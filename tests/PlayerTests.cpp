

#include <boost/test/unit_test.hpp>
#include <Room.hpp>
#include <Player.hpp>

#include "Helpers/TestConnectionProtocolHandler.hpp"
#include "Helpers/TestSignalSendDelegate.hpp"


BOOST_AUTO_TEST_SUITE(PlayerTestSuite)


    BOOST_AUTO_TEST_CASE(SettingAndResettingRoom){

            std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
            TestConnectionProtocolHandler protocolHandler;

            std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));


            std::shared_ptr<Room> room (new Room(0));

            BOOST_CHECK_EQUAL(room.use_count(),1);

            room->joinRoom(player1);

            BOOST_CHECK_EQUAL(room.use_count(),2);
            BOOST_CHECK_EQUAL(player1.use_count(),2);


            room->leaveRoom(player1);

            BOOST_CHECK_EQUAL(room.use_count(),1);
            BOOST_CHECK_EQUAL(player1.use_count(),1);


            room->leaveRoom(player1);

            BOOST_CHECK_EQUAL(room.use_count(),1);
            BOOST_CHECK_EQUAL(player1.use_count(),1);

    }



BOOST_AUTO_TEST_SUITE_END()