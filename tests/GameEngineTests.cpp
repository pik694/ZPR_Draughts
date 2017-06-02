//
// Created by Piotr Żelazko on 24.04.2017.
//

#include <boost/test/unit_test.hpp>


#include <OutputStreams.cpp>
#include <GameLogic/Game.hpp>
#include <GameLogic/Board.hpp>
#include <GameLogic/Point.hpp>
#include <GameLogic/PieceKind.hpp>
#include <GameLogic/PlayerColour.hpp>

class TestGameObserver : public GameObserver{
public:
    TestGameObserver():somebodyWon_(false){}

    virtual void playerWon(PlayerColour player){
        somebodyWon_ = true;
        whoWon_ = player;
    }

    bool hasSomebodyWon(){
        return somebodyWon_;
    }

    PlayerColour whoWon(){
        return whoWon_;
    }

private:

    bool somebodyWon_;
    PlayerColour whoWon_;

};


void testBoard (const Board& board, std::vector < std::pair <Point, PieceKind> > pathToBeChecked){
    for (auto pair : pathToBeChecked){

        BOOST_CHECK_EQUAL(board.getPieceAt(pair.first, PlayerColour::white), pair.second);
    }
}


BOOST_AUTO_TEST_SUITE(GameEngineTests)


    BOOST_AUTO_TEST_CASE(ValidMensMovesWithoutCapture){

        Game game;

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(0, 2), Point(1, 3)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(0, 2), Point(1, 3)));

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(1, 3), Point(0, 4)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(1, 3), Point(0, 4)));

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(1, 1), Point(0, 2)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(1, 1), Point(0, 2)));

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(0, 0), Point(1, 1)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(0, 0), Point(1, 1)));

        BOOST_CHECK(game.makeMove(PlayerColour::white, Point(6, 2), Point(5, 3)));
        BOOST_CHECK(game.makeMove(PlayerColour::black, Point(6, 2), Point(5, 3)));

    }

    BOOST_AUTO_TEST_CASE(ChangingTurns){

        Game game;

        game.makeMove(PlayerColour::white, Point(0, 2), Point(1, 3));
        BOOST_CHECK_EQUAL(game.whoseTurn(), PlayerColour::black);

        game.makeMove(PlayerColour::black, Point(0, 2), Point(1, 3));
        BOOST_CHECK_EQUAL(game.whoseTurn(), PlayerColour::white);

        game.makeMove(PlayerColour::black, Point(1, 1), Point(0, 2));
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


            BOOST_CHECK(game.makeMove(PlayerColour::white, Point(0, 0), Point(2, 2)));

            BOOST_CHECK_EQUAL(game.getBoard(PlayerColour::white).getPieceAt(Point(0, 0), PlayerColour::white), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getBoard(PlayerColour::white).getPieceAt(Point(1, 1), PlayerColour::white), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getBoard(PlayerColour::white).getPieceAt(Point(2, 2), PlayerColour::white), PieceKind::whiteMen);


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
                            {PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));

            game.makeMove(PlayerColour::white, Point(0, 0), Point(1, 1));
            BOOST_CHECK(game.makeMove(PlayerColour::black, Point(7, 1), Point(5, 3)));

            BOOST_CHECK_EQUAL(game.getBoard(PlayerColour::white).getPieceAt(Point(7, 1), PlayerColour::black), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getBoard(PlayerColour::white).getPieceAt(Point(6, 2), PlayerColour::black), PieceKind::none);
            BOOST_CHECK_EQUAL(game.getBoard(PlayerColour::white).getPieceAt(Point(5, 3), PlayerColour::black), PieceKind::blackMen);
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


        BOOST_CHECK(game.makeMove(PlayerColour::white, {Point(0,0), Point(2,2), Point(4,4), Point(2, 6)}));


        testBoard(game.getBoard(PlayerColour::white), {
                {Point(0,0), PieceKind::none},
                {Point(1,1), PieceKind::none},
                {Point(2,2), PieceKind::none},
                {Point(3,3), PieceKind::none},
                {Point(4,4), PieceKind::none},
                {Point(3,5), PieceKind::none},
                {Point(2,6), PieceKind::whiteMen}
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


        BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0,0), Point(2,2), Point(4,4), Point(2, 6)}), false);


        testBoard(game.getBoard(PlayerColour::white), {
                {Point(0,0), PieceKind::whiteMen},
                {Point(1,1), PieceKind::blackMen},
                {Point(2,2), PieceKind::none},
                {Point(3,3), PieceKind::blackMen},
                {Point(4,4), PieceKind::none},
                {Point(3,5), PieceKind::blackMen},
                {Point(2,6), PieceKind::blackMen}
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1, 1), Point(2, 2), Point(4, 4), Point(2, 6)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::none},
                    {Point(3, 5), PieceKind::blackMen},
                    {Point(2, 6), PieceKind::blackMen}
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1, 0), Point(2, 2), Point(4, 4), Point(2, 6)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::none},
                    {Point(3, 5), PieceKind::blackMen},
                    {Point(2, 6), PieceKind::blackMen}
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(2, 0), Point(2, 2), Point(4, 4), Point(2, 6)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::none},
                    {Point(3, 5), PieceKind::blackMen},
                    {Point(2, 6), PieceKind::blackMen}
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(1, 1)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen}
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(-1, 1)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen}
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(1,7), Point(0, 8)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(1, 7), PieceKind::whiteKing},
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(7, 1), Point(2, 8)}), false);

            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(7, 1), PieceKind::whiteMen},
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(2, 2), Point(4,4), Point(2,6)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::none},
                    {Point(3, 5), PieceKind::blackMen},
                    {Point(2, 6), PieceKind::blackMen}
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(2, 2), Point(4,4), Point(2,6), Point(1, 7)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::none},
                    {Point(3, 5), PieceKind::blackMen},
                    {Point(2, 6), PieceKind::none},
                    {Point(1,7), PieceKind::blackMen}
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


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(2, 2), Point(4,4), Point(2,6), Point(3, 7)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::none},
                    {Point(3, 5), PieceKind::blackMen},
                    {Point(2, 6), PieceKind::none},
                    {Point(3,7), PieceKind::none}
            });
        }
    }

    BOOST_AUTO_TEST_CASE(InvalidPositionInPathWhenCapturingSeveral){

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(2, 2), Point(4,4)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::blackMen}
            });
        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(2, 2), Point(5,5)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::blackMen}
            });
        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(2, 2), Point(4,3)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::blackMen}
            });
        }




    }

    BOOST_AUTO_TEST_CASE(InvalidCapturingBackwardsCase){

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::whiteMen, PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(2, 4), Point(4, 2)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(2, 4), PieceKind::whiteMen},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 2), PieceKind::none}
            });
        }

    }

    BOOST_AUTO_TEST_CASE(InvalidCapturingSeveralBackwardsCase){

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::blackMen, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(2, 2), Point(4,4), Point(6, 2)}), false);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(0, 0), PieceKind::whiteMen},
                    {Point(1, 1), PieceKind::blackMen},
                    {Point(2, 2), PieceKind::none},
                    {Point(3, 3), PieceKind::blackMen},
                    {Point(4, 4), PieceKind::none},
                    {Point(5, 3), PieceKind::blackMen},
                    {Point(6, 2), PieceKind::none}
            });
        }


    }

    BOOST_AUTO_TEST_CASE(MenChangesIntoAKing){

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::whiteMen,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::blackMen, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(2, 6), Point(3, 7)}), true);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(2, 6), PieceKind::none},
                    {Point(3, 7), PieceKind::whiteKing}
            });
        }

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::none, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::blackMen,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::whiteMen, PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::blackMen, PieceKind::none, PieceKind::blackMen, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(3, 5), Point(1, 7)}), true);


            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(3, 5), PieceKind::none},
                    {Point(2, 6), PieceKind::none},
                    {Point(1, 7), PieceKind::whiteKing}
            });
        }


    }

    BOOST_AUTO_TEST_CASE(PlayerWon){

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));

            TestGameObserver gameObserver;

            game.setGameObserver(&gameObserver);


            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(0, 0), Point(2, 2)}), true);

            BOOST_CHECK_EQUAL(gameObserver.hasSomebodyWon(), true);
            BOOST_CHECK_EQUAL(gameObserver.whoWon(), PlayerColour::white);

        }


    }

    BOOST_AUTO_TEST_CASE(ValidKingsMovesWithoutCapture){

        {
            Game game(std::move(Board(
                    {
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::none,     PieceKind::whiteKing,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::none,     PieceKind::blackMen, PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                            {PieceKind::whiteMen, PieceKind::none,     PieceKind::none,     PieceKind::none,     PieceKind::none, PieceKind::none, PieceKind::none, PieceKind::none},
                    }
            )));

            TestGameObserver gameObserver;

            game.setGameObserver(&gameObserver);

            BOOST_CHECK_EQUAL(game.makeMove(PlayerColour::white, {Point(2, 2), Point(0, 4)}), true);

            testBoard(game.getBoard(PlayerColour::white), {
                    {Point(2, 2), PieceKind::none},
                    {Point(1, 3), PieceKind::none},
                    {Point(0, 4), PieceKind::whiteKing}
            });



            BOOST_CHECK_EQUAL(gameObserver.hasSomebodyWon(), false);

        }

    }

BOOST_AUTO_TEST_SUITE_END()