//
// Created by Piotr Żelazko on 24.04.2017.
//

#include <boost/test/unit_test.hpp>

#include <Game.hpp>
#include <Board.hpp>
#include <Point.hpp>
#include <PieceKind.hpp>
#include <PlayerColour.hpp>

#include <exception>


using namespace{

    using PlayerColour::black;
    using PlayerColour::white;

    using PieceKind::none;
    using PieceKind::whiteMen;
    using PieceKind::blackMen;
    using PieceKind::whiteKing;
    using PieceKind::blackKing;
}



BOOST_AUTO_TEST_SUITE(GameEngineTests)



    BOOST_AUTO_TEST_CASE(InvalidPlayersGivenToTheConstructor){



    }

    BOOST_AUTO_TEST_CASE(ValidMensMovesWithoutCapture){

        Game game;

        BOOST_CHECK(game.makeMove(white, Point(3, 1), Point(4, 2)));
        BOOST_CHECK(game.makeMove(black, Point(3, 1), Point(4, 2)));

        BOOST_CHECK(game.makeMove(white, Point(4, 2), Point(5, 1)));
        BOOST_CHECK(game.makeMove(black, Point(4, 2), Point(5, 1)));

        BOOST_CHECK(game.makeMove(white, Point(2, 2), Point(3, 1)));
        BOOST_CHECK(game.makeMove(black, Point(2, 2), Point(3, 1)));

        BOOST_CHECK(game.makeMove(white, Point(2, 2), Point(3, 1)));
        BOOST_CHECK(game.makeMove(black, Point(2, 2), Point(3, 1)));

        BOOST_CHECK(game.makeMove(white, Point(3, 1), Point(4, 2)));
        BOOST_CHECK(game.makeMove(black, Point(3, 1), Point(4, 2)));


    }


    BOOST_AUTO_TEST_CASE(ChangingTurns){

        Game game;

        game.makeMove(white, Point(3, 1), Point(4, 2));
        BOOST_CHECK_EQUAL(game.whoseTurn(), black);

        game.makeMove(black, Point(4,2), Point(5,1));
        BOOST_CHECK_EQUAL(game.whoseTurn(), white);

        game.makeMove(black, Point(2, 2), Point(3, 1));
        BOOST_CHECK_EQUAL(game.whoseTurn(), white);


    }

    BOOST_AUTO_TEST_CASE(ValidMensMovesWithSingleCapture){


        Game game ( std::move( Board (
            {
                { none, blackMen, none, none, none, none, none, none },
                { none, none, none, none, none, none, none, none },
                { none, none, none, none, none, none, none, none },
                { none, none, none, none, none, none, none, none },
                { none, none, none, none, none, none, none, none },
                { none, blackMen, none, none, none, none, none, none },
                { whiteMen, none, none, none, none, none, none, none },
            }
        )));


        BOOST_CHECK(game.makeMove(white, Point(1, 1), Point(3,3)));

        BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point (2, 2)), none);
        BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(1,1)), none);
        BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(3,3)), whiteMen);


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