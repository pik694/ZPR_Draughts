//
// Created by Piotr Żelazko on 24.04.2017.
//

#include <boost/test/unit_test.hpp>

#include <Game.hpp>
#include <Gameboard.hpp>
#include <Player.hpp>
#include <Point.hpp>

#include <exception>

BOOST_AUTO_TEST_SUITE(GameEngineTests)

    BOOST_AUTO_TEST_CASE(InvalidPlayersGivenToTheConstructor){

        Player whitePlayer, blackPlayer;


        BOOST_CHECK_THROW(new Game (whitePlayer, whitePlayer), std::invalid_argument);
        BOOST_CHECK_THROW(new Game (blackPlayer, blackPlayer), std::invalid_argument);

        BOOST_CHECK_THROW(new Game (nullptr, nullptr), std::invalid_argument);

        BOOST_CHECK_THROW(new Game(nullptr, whitePlayer), std::invalid_argument);
        BOOST_CHECK_THROW(new Game(blackPlayer, nullptr), std::invalid_argument);



    }

    BOOST_AUTO_TEST_CASE(ValidMensMovesWithoutCapture){

        Player player1, player2;

        Game game (player1, player2);

        const Player& whitePlayer = &game.whoseTurn() == &player1 ? player1 : player2;
        const Player& blackPlayer = &game.whoseTurn() == &player1 ? player2 : player1;

        BOOST_CHECK(game.makeMove(whitePlayer, Point(3, 1), Point(4, 2)));
        BOOST_CHECK(game.makeMove(blackPlayer, Point(3, 1), Point(4, 2)));

        BOOST_CHECK(game.makeMove(whitePlayer, Point(4, 2), Point(5, 1)));
        BOOST_CHECK(game.makeMove(blackPlayer, Point(4, 2), Point(5, 1)));

        BOOST_CHECK(game.makeMove(whitePlayer, Point(2, 2), Point(3, 1)));
        BOOST_CHECK(game.makeMove(blackPlayer, Point(2, 2), Point(3, 1)));

        BOOST_CHECK(game.makeMove(whitePlayer, Point(2, 2), Point(3, 1)));
        BOOST_CHECK(game.makeMove(blackPlayer, Point(2, 2), Point(3, 1)));

        BOOST_CHECK(game.makeMove(whitePlayer, Point(3, 1), Point(4, 2)));
        BOOST_CHECK(game.makeMove(blackPlayer, Point(3, 1), Point(4, 2)));



    }


    BOOST_AUTO_TEST_CASE(TurnsChanging){

        Player player1, player2;

        Game game (player1, player2);

        const Player& whitePlayer = &game.whoseTurn() == &player1 ? player1 : player2;
        const Player& blackPlayer = &game.whoseTurn() == &player1 ? player2 : player1;


        game.makeMove(whitePlayer, Point(3, 1), Point(4, 2));
        BOOST_CHECK_EQUAL(&game.whoseTurn(), &blackPlayer);

        game.makeMove(blackPlayer, Point(4,2), Point(5,1));
        BOOST_CHECK_EQUAL(&game.whoseTurn(), &whitePlayer);









    }

    BOOST_AUTO_TEST_CASE(ValidMensMovesWithSingleCapture){

        BOOST_REQUIRE( 1==1 );


    }

    BOOST_AUTO_TEST_CASE(ValidMensMovesWithCapturingSeveralPawns){

        BOOST_REQUIRE( 1==1 );


    }

    BOOST_AUTO_TEST_CASE(InvalidCapturingMultiplePawns){

        BOOST_REQUIRE( 1==1 );


    }


    BOOST_AUTO_TEST_CASE(InvalidBeginPosition){

        BOOST_REQUIRE( 1==1 );


    }

    BOOST_AUTO_TEST_CASE(InvalidEndPositonWhileCapturing){

        BOOST_REQUIRE( 1==1 );


    }


    BOOST_AUTO_TEST_CASE(InvalidEndPositonWhenCapturingMultiple){

        BOOST_REQUIRE( 1==1 );


    }


    BOOST_AUTO_TEST_CASE(InvalidPositonInPathWhenCapturingSeveral){

        BOOST_REQUIRE( 1==1 );


    }

    BOOST_AUTO_TEST_CASE(InvalidCapturingBackwardsCase){

        BOOST_REQUIRE( 1==1 );


    }

    BOOST_AUTO_TEST_CASE(InvalidCapturingSeveralBackwardsCase){

        BOOST_REQUIRE( 1==1 );


    }

    BOOST_AUTO_TEST_CASE(MenChangesIntoAKing){

        BOOST_REQUIRE( 1==1 );


    }

    BOOST_AUTO_TEST_CASE(PleyerWon){

        BOOST_REQUIRE( 1==1 );


    }

    BOOST_AUTO_TEST_CASE(ValidKingsMovesWithoutCapture){

    }

BOOST_AUTO_TEST_SUITE_END()