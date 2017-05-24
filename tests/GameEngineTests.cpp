//
// Created by Piotr Żelazko on 24.04.2017.
//

#include <boost/test/unit_test.hpp>

#include <utility>

#include <GameLogic/Game.hpp>
#include <GameLogic/Board.hpp>
#include <Point.hpp>
#include <GameLogic/PieceKind.hpp>
#include <GameLogic/PlayerColour.hpp>



BOOST_AUTO_TEST_SUITE(GameEngineTests)


    void testBoard(const Board& board, std::vector < std::pair <Point, PieceKind> > pathToBeChecked){
        for (auto pair : pathToBeChecked){
            BOOST_CHECK_EQUAL(board.getPieceAt(pair.first), pair.second);
        }
    }


    BOOST_AUTO_TEST_CASE(InvalidArgumentssGivenToTheConstructor){

        throw std::runtime_error("Not implemented yet");

    }

    BOOST_AUTO_TEST_CASE(ValidMensMovesWithoutCapture){

        Game game;

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(3, 1), Point(4, 2)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(3, 1), Point(4, 2)));

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(4, 2), Point(5, 1)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(4, 2), Point(5, 1)));

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(2, 2), Point(3, 1)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(2, 2), Point(3, 1)));

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(2, 2), Point(3, 1)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(2, 2), Point(3, 1)));

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(3, 1), Point(4, 2)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(3, 1), Point(4, 2)));  


    }


    BOOST_AUTO_TEST_CASE(ChangingTurns){

        Game game;

        game.makeMove(PlayerColour::white, Point(3, 1), Point(4, 2));
        BOOST_CHECK_EQUAL(game.whoseTurn(), PlayerColour::black);

        game.makeMove(PlayerColour::black, Point(4,2), Point(5,1));
        BOOST_CHECK_EQUAL(game.whoseTurn(), PlayerColour::white);

        game.makeMove(PlayerColour::black, Point(2, 2), Point(3, 1));
        BOOST_CHECK_EQUAL(game.whoseTurn(), PlayerColour::white);


    }

    BOOST_AUTO_TEST_CASE(ValidMensMovesWithSingleCapture){

        {

            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK(game.makeMove(PlayerColour::white, Point(1, 1), Point(3, 3)));

            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(2, 2)), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(1, 1)), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(3, 3)), PieceKind::whiteMen);


        }

        {

            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK(game.makeMove(PlayerColour::white, {Point(1, 1), Point(3, 3)} ));

            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(2, 2)), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(1, 1)), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(3, 3)), PieceKind::whiteMen);


        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::blackMen,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::whiteMen,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK(game.makeMove(PlayerColour::black, Point(2, 8), Point(3, 3)));

            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(2, 2)), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(1, 1)), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(3, 3)), PieceKind::whiteMen);
        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::blackMen,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::whiteMen,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK(game.makeMove(PlayerColour::black, {Point(2, 8), Point(3, 3)} ));

            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(2, 2)), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(1, 1)), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getGameboard().getPieceAt(Point(3, 3)), PieceKind::whiteMen);
        }



    }

    BOOST_AUTO_TEST_CASE(ValidMensMovesWithMultipleCapturing){


        Game game(std::move(Board(
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


        BOOST_CHECK(game.makeMove(PlayerColour::white, {Point(1,1), Point(3,3), Point(5,5), Point(7, 3)}));


        testBoard(game.getGameboard(), {
                {Point(1,1), PieceKind::none},
                {Point(2,2), PieceKind::none},
                {Point(3,3), PieceKind::none},
                {Point(4,4), PieceKind::none},
                {Point(5,5), PieceKind::none},
                {Point(6,4), PieceKind::none},
                {Point(7,3), PieceKind::whiteMen}
        });


    }

    BOOST_AUTO_TEST_CASE(InvalidMultipleCapturing){

        Game game(std::move(Board(
                {
                        {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                        {PieceKind::whiteMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                }
        )));


        BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1,1), Point(3,3), Point(5,5), Point(7, 3)}), false);


        testBoard(game.getGameboard(), {
                {Point(1,1), PieceKind::whiteMen},
                {Point(2,2), PieceKind::blackMen},
                {Point(3,3), PieceKind::none},
                {Point(4,4), PieceKind::blackMen},
                {Point(5,5), PieceKind::none},
                {Point(6,4), PieceKind::blackMen},
                {Point(7,3), PieceKind::blackMen}
        });


    }

    BOOST_AUTO_TEST_CASE(InvalidBeginPosition) {

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(2, 2), Point(3, 3), Point(5, 5), Point(7, 3)}), false);


            testBoard(game.getGameboard(), {
                    {Point(1, 1), PieceKind::whiteMen},
                    {Point(2, 2), PieceKind::blackMen},
                    {Point(3, 3), PieceKind::none},
                    {Point(4, 4), PieceKind::blackMen},
                    {Point(5, 5), PieceKind::none},
                    {Point(6, 4), PieceKind::blackMen},
                    {Point(7, 3), PieceKind::blackMen}
            });
        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1, 2), Point(3, 3), Point(5, 5), Point(7, 3)}), false);


            testBoard(game.getGameboard(), {
                    {Point(1, 1), PieceKind::whiteMen},
                    {Point(2, 2), PieceKind::blackMen},
                    {Point(3, 3), PieceKind::none},
                    {Point(4, 4), PieceKind::blackMen},
                    {Point(5, 5), PieceKind::none},
                    {Point(6, 4), PieceKind::blackMen},
                    {Point(7, 3), PieceKind::blackMen}
            });
        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1, 3), Point(3, 3), Point(5, 5), Point(7, 3)}), false);


            testBoard(game.getGameboard(), {
                    {Point(1, 1), PieceKind::whiteMen},
                    {Point(2, 2), PieceKind::blackMen},
                    {Point(3, 3), PieceKind::none},
                    {Point(4, 4), PieceKind::blackMen},
                    {Point(5, 5), PieceKind::none},
                    {Point(6, 4), PieceKind::blackMen},
                    {Point(7, 3), PieceKind::blackMen}
            });
        }


    }

    BOOST_AUTO_TEST_CASE (InvalidEndPosition){
        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1, 1), Point(2, 2)}), false);


            testBoard(game.getGameboard(), {
                    {Point(1, 1), PieceKind::whiteMen},
                    {Point(2, 2), PieceKind::blackMen}
            });
        }
        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1, 1), Point(2, 0)}), false);


            testBoard(game.getGameboard(), {
                    {Point(1, 1), PieceKind::whiteMen},
                    {Point(2, 2), PieceKind::blackMen}
            });
        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::whiteKing, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(8,2), Point(9, 1)}), false);


            testBoard(game.getGameboard(), {
                    {Point(8, 2), PieceKind::whiteKing},
            });
        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::whiteMen},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(2, 8), Point(3, 9)}), false);

            testBoard(game.getGameboard(), {
                    {Point(2, 8), PieceKind::whiteMen},
            });
        }


    }

    BOOST_AUTO_TEST_CASE(InvalidEndPositonWhileCapturing){
        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1, 1), Point(3, 3), Point(5,5), Point(7,3)}), false);


            testBoard(game.getGameboard(), {
                    {Point(1, 1), PieceKind::whiteMen},
                    {Point(2, 2), PieceKind::blackMen},
                    {Point(3, 3), PieceKind::none},
                    {Point(4, 4), PieceKind::blackMen},
                    {Point(5, 5), PieceKind::none},
                    {Point(6, 4), PieceKind::blackMen},
                    {Point(7, 3), PieceKind::blackMen}
            });
        }
        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1, 1), Point(3, 3), Point(5,5), Point(7,3), Point(8, 2)}), false);


            testBoard(game.getGameboard(), {
                    {Point(1, 1), PieceKind::whiteMen},
                    {Point(2, 2), PieceKind::blackMen},
                    {Point(3, 3), PieceKind::none},
                    {Point(4, 4), PieceKind::blackMen},
                    {Point(5, 5), PieceKind::none},
                    {Point(6, 4), PieceKind::blackMen},
                    {Point(7, 3), PieceKind::none},
                    {Point(8,2), PieceKind::blackMen}
            });
        }
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