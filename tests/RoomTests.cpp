//
// Created by Piotr Żelazko on 02.06.2017.
//

#include <boost/test/unit_test.hpp>
#include <Signals/OpponentEnteredTheRoomSignal.hpp>
#include <Signals/BoardSignal.hpp>
#include <Signals/OpponentLeftRoomSignal.hpp>
#include <Signals/TextMessage.hpp>

#include "Room.hpp"
#include "Player.hpp"
#include "Helpers/TestSignalSendDelegate.hpp"
#include "Helpers/TestConnectionProtocolHandler.hpp"



BOOST_AUTO_TEST_SUITE(RoomTests)

    BOOST_AUTO_TEST_CASE(PlayersJoinningAndLeavingRoom){


        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateTwo (new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateThree (new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));
        std::shared_ptr<Player> player2 (new Player("player_two", &protocolHandler, delegateTwo));
        std::shared_ptr<Player> player3 (new Player("player_three", &protocolHandler, delegateThree));


        std::shared_ptr<Room> room (new Room(0));
        {
            BOOST_CHECK(room->joinRoom(player1));
            BOOST_CHECK(room->joinRoom(player2));
            BOOST_CHECK(!room->joinRoom(player3));

            BOOST_CHECK(player1->getRoom() == room);
            BOOST_CHECK(player2->getRoom() == room);
            BOOST_CHECK(player3->getRoom() == nullptr);
        }

        {
            BOOST_CHECK(room->leaveRoom(player1));
            BOOST_CHECK(!room->leaveRoom(player3));

            BOOST_CHECK(player1->getRoom() == nullptr);
            BOOST_CHECK(player2->getRoom() == room);
            BOOST_CHECK(player3->getRoom() == nullptr);
        }

        {
            BOOST_CHECK(room->joinRoom(player3));
            BOOST_CHECK(room->leaveRoom(player2));

            BOOST_CHECK(player1->getRoom() == nullptr);
            BOOST_CHECK(player2->getRoom() == nullptr);
            BOOST_CHECK(player3->getRoom() == room);
        }

        {
            BOOST_CHECK(!room->joinRoom(player3));
            BOOST_CHECK(!room->leaveRoom(player2));
            BOOST_CHECK(!room->leaveRoom(player1));


            BOOST_CHECK(player1->getRoom() == nullptr);
            BOOST_CHECK(player2->getRoom() == nullptr);
            BOOST_CHECK(player3->getRoom() == room);
        }


    }

    BOOST_AUTO_TEST_CASE(PlayerTriesToJoinTwoRoomsAtOnce){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));

        std::shared_ptr<Room> firstRoom (new Room(0));
        std::shared_ptr<Room> secondRoom (new Room(1));

        BOOST_CHECK(firstRoom->joinRoom(player1));
        BOOST_CHECK(!secondRoom->joinRoom(player1));

        BOOST_CHECK(firstRoom->leaveRoom(player1));
        BOOST_CHECK(secondRoom->joinRoom(player1));
        BOOST_CHECK(!secondRoom->joinRoom(player1));
        BOOST_CHECK((!firstRoom->joinRoom(player1)));

    }

    BOOST_AUTO_TEST_CASE(StartingGame){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateTwo (new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));
        std::shared_ptr<Player> player2 (new Player("player_two", &protocolHandler, delegateTwo));


        std::shared_ptr<Room> room (new Room(0));


        BOOST_CHECK(room->joinRoom(player1));
        BOOST_CHECK(!room->startNewGame());

        BOOST_CHECK(room->joinRoom(player2));
        BOOST_CHECK(room->startNewGame());

        BOOST_CHECK(room->leaveRoom(player1));
        BOOST_CHECK(!room->startNewGame());

        BOOST_CHECK(room->joinRoom(player1));
        BOOST_CHECK(room->startNewGame());

        std::shared_ptr<Signal> signal;
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK_EQUAL(dynamic_cast<OpponentEnteredTheRoomSignal*>(signal.get())->getOpponentNick(),  "player_two");
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK_EQUAL(dynamic_cast<OpponentEnteredTheRoomSignal*>(signal.get())->getOpponentNick(),  "player_two");
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);


        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK_EQUAL(dynamic_cast<OpponentEnteredTheRoomSignal*>(signal.get())->getOpponentNick(),  "player_one");
        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);
        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<OpponentLeftRoomSignal*>(signal.get()) != nullptr);

       // delegateTwo->getSignal();

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK_EQUAL(dynamic_cast<OpponentEnteredTheRoomSignal*>(signal.get())->getOpponentNick(),  "player_one");
        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);

    }

    BOOST_AUTO_TEST_CASE(SendingTextMessageBeforeGameStarted){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateTwo (new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));
        std::shared_ptr<Player> player2 (new Player("player_two", &protocolHandler, delegateTwo));


        std::shared_ptr<Room> room (new Room(0));


        BOOST_CHECK(room->joinRoom(player1));

        room->sendTextMessage(player1, "TextMessage");

        std::shared_ptr<Signal> signal;
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<TextMessage*>(signal.get())!= nullptr);


        room->joinRoom(player2);
        room->sendTextMessage(player1, "TextMessage");

        delegateOne->getSignal();
        delegateTwo->getSignal();

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<TextMessage*>(signal.get())->getMessage() == "TextMessage");
        BOOST_CHECK(delegateOne->getSignal() == nullptr);


    }


    BOOST_AUTO_TEST_CASE(SendingTextMessages){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateTwo (new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));
        std::shared_ptr<Player> player2 (new Player("player_two", &protocolHandler, delegateTwo));


        std::shared_ptr<Room> room (new Room(0));


        BOOST_CHECK(room->joinRoom(player1));

        room->sendTextMessage(player1, "TextMessage");

        std::shared_ptr<Signal> signal;
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<TextMessage*>(signal.get())!= nullptr);


        room->joinRoom(player2);
        room->sendTextMessage(player1, "TextMessage");

        delegateOne->getSignal();
        delegateTwo->getSignal();

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<TextMessage*>(signal.get())->getMessage() == "TextMessage");
        BOOST_CHECK(delegateOne->getSignal() == nullptr);


        room->startNewGame();

        delegateOne->getSignal();
        delegateTwo->getSignal();


        room->sendTextMessage(player1, "TextMessage1");
        room->sendTextMessage(player2, "TextMessage2");

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<TextMessage*>(signal.get())->getMessage() == "TextMessage1");
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<TextMessage*>(signal.get())->getMessage() == "TextMessage2");


    }

    BOOST_AUTO_TEST_CASE(SendingMovesWithoutSecondPlayer){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));

        std::shared_ptr<Room> room (new Room(0));

        BOOST_CHECK(room->joinRoom(player1));

        BOOST_CHECK_NO_THROW(room->makeMove({{2,0},{3,1}}, player1));

        BOOST_CHECK(!room->startNewGame());
        BOOST_CHECK_NO_THROW(room->makeMove({{2,0},{3,1}}, player1));

        BOOST_CHECK(delegateOne->getSignal() == nullptr);

    }

    BOOST_AUTO_TEST_CASE(SendingMovesWihoutGameBeingInProgress){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateTwo (new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));
        std::shared_ptr<Player> player2 (new Player("player_two", &protocolHandler, delegateTwo));


        std::shared_ptr<Room> room (new Room(0));

        room->joinRoom(player1);
        room->joinRoom(player2);

        delegateOne->getSignal();
        delegateTwo->getSignal();

        BOOST_CHECK_NO_THROW(room->makeMove({{2,0}, {3,1}}, player1));
        BOOST_CHECK_NO_THROW(room->makeMove({{2,0}, {3,1}}, player2));

        BOOST_CHECK(delegateOne->getSignal() == nullptr);
        BOOST_CHECK(delegateTwo->getSignal() == nullptr);

    }

    BOOST_AUTO_TEST_CASE(PlayerLeavesDuringGame){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateTwo (new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));
        std::shared_ptr<Player> player2 (new Player("player_two", &protocolHandler, delegateTwo));


        std::shared_ptr<Room> room (new Room(0));
        std::shared_ptr<Signal> signal;

        room->joinRoom(player1);
        room->joinRoom(player2);

        delegateOne->getSignal();
        delegateTwo->getSignal();

        BOOST_CHECK(room->startNewGame());

        delegateOne->getSignal();
        delegateTwo->getSignal();


        BOOST_CHECK_NO_THROW(room->makeMove({{2,0}, {3,1}}, player1));

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);

        BOOST_CHECK_NO_THROW(room->makeMove({{2,0}, {3,1}}, player2));

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);


        room->leaveRoom(player1);

        delegateTwo->getSignal();

        BOOST_CHECK_NO_THROW(room->makeMove({{3,1}, {0,4}}, player2));
        BOOST_CHECK_NO_THROW(room->makeMove({{3,1}, {0,4}}, player1));

        BOOST_CHECK(delegateOne->getSignal() == nullptr);
        BOOST_CHECK(delegateTwo->getSignal() == nullptr);

    }

    BOOST_AUTO_TEST_CASE(PlayerLeavesDuringGameAndAnotherComes){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateTwo (new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player1 (new Player("player_one",&protocolHandler, delegateOne));
        std::shared_ptr<Player> player2 (new Player("player_two", &protocolHandler, delegateTwo));


        std::shared_ptr<Room> room (new Room(0));
        std::shared_ptr<Signal> signal;

        room->joinRoom(player1);
        room->joinRoom(player2);

        delegateOne->getSignal();
        delegateTwo->getSignal();

        BOOST_CHECK(room->startNewGame());

        delegateOne->getSignal();
        delegateTwo->getSignal();


        BOOST_CHECK_NO_THROW(room->makeMove({{2,0}, {3,1}}, player1));

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);

        BOOST_CHECK_NO_THROW(room->makeMove({{2,0}, {3,1}}, player2));

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);
        BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<BoardSignal*>(signal.get()) != nullptr);


        room->leaveRoom(player1);
        room->joinRoom(player1);

        delegateTwo->getSignal();
        delegateOne->getSignal();
        delegateTwo->getSignal();

        BOOST_CHECK_NO_THROW(room->makeMove({{3,1}, {0,4}}, player2));
        BOOST_CHECK_NO_THROW(room->makeMove({{3,1}, {0,4}}, player1));

        BOOST_CHECK(delegateOne->getSignal() == nullptr);
        BOOST_CHECK(delegateTwo->getSignal() == nullptr);


    }


    BOOST_AUTO_TEST_CASE(PlayerDisconnectsWhileBeingInRoom){

        std::shared_ptr<TestSignalSendDelegate> delegateOne(new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateTwo (new TestSignalSendDelegate());
        std::shared_ptr<TestSignalSendDelegate> delegateThree (new TestSignalSendDelegate());
        TestConnectionProtocolHandler protocolHandler;

        std::shared_ptr<Player> player2 (new Player("player_two", &protocolHandler, delegateTwo));
        std::shared_ptr<Player> player3 (new Player("player_three", &protocolHandler, delegateThree));

        std::shared_ptr<Room> room (new Room(0));
        std::shared_ptr<Signal> signal;

        {
            std::shared_ptr<Player> player1(new Player("player_one", &protocolHandler, delegateOne));

            room->joinRoom(player1);
            room->joinRoom(player2);


            BOOST_REQUIRE( (signal = delegateOne->getSignal()) != nullptr);
            BOOST_CHECK_EQUAL(dynamic_cast<OpponentEnteredTheRoomSignal*>(signal.get())->getOpponentNick(),  "player_two");
            BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
            BOOST_CHECK_EQUAL(dynamic_cast<OpponentEnteredTheRoomSignal*>(signal.get())->getOpponentNick(),  "player_one");

            room->leaveRoom(player1);
        }

        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK(dynamic_cast<OpponentLeftRoomSignal*>(signal.get()) != nullptr);

        BOOST_CHECK(room->joinRoom(player3));

        BOOST_REQUIRE( (signal = delegateThree->getSignal()) != nullptr);
        BOOST_CHECK_EQUAL(dynamic_cast<OpponentEnteredTheRoomSignal*>(signal.get())->getOpponentNick(),  "player_two");
        BOOST_REQUIRE( (signal = delegateTwo->getSignal()) != nullptr);
        BOOST_CHECK_EQUAL(dynamic_cast<OpponentEnteredTheRoomSignal*>(signal.get())->getOpponentNick(),  "player_three");



    }




BOOST_AUTO_TEST_SUITE_END()