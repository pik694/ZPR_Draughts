

#include <boost/test/unit_test.hpp>
#include <Player.hpp>

BOOST_AUTO_TEST_SUITE(PlayerTestSuite)

BOOST_AUTO_TEST_CASE(setNick) {
        Player my_player;
        my_player.SetNickName("123");
        BOOST_REQUIRE(my_player.getName() == "123");
}

BOOST_AUTO_TEST_SUITE_END()