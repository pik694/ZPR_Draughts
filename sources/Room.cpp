#include <Signals/OpponentEnteredTheRoomSignal.hpp>
#include <Signals/GameEndSignal.hpp>
#include <Signals/BoardSignal.hpp>
#include <Signals/TextMessage.hpp>
#include <Signals/OpponentLeftRoomSignal.hpp>
#include "Room.hpp"
#include "Server.hpp"
#include "RoomManager.hpp"

Room::Room(int ID) :
        whitePlayer_(nullptr),
        blackPlayer_(nullptr),
        numberOfPlayers_(0),
        roomID_(ID) {}

bool Room::isOpponent() {
    return numberOfPlayers_ == 1;
}
bool Room::joinRoom(player_ptr player) {

    if (numberOfPlayers_ == 2) return false;

    if (whitePlayer_ == nullptr) {
        whitePlayer_ = player;
    } else {
        blackPlayer_ = player;
    }

    if (numberOfPlayers_ == 1) {

        player_ptr opponent = player == whitePlayer_ ? blackPlayer_ : whitePlayer_;

        Server::getInstance()->putMessageInQueue(
                std::make_shared<OpponentEnteredTheRoomSignal>(blackPlayer_->getConnectionProtocolHandler(),
                                                               whitePlayer_->getName())
        );

        Server::getInstance()->putMessageInQueue(
                std::make_shared<OpponentEnteredTheRoomSignal>(whitePlayer_->getConnectionProtocolHandler(),
                                                               blackPlayer_->getName())
        );
    }

    player->setRoom(roomID_);

    ++numberOfPlayers_;

    return true;

}

bool Room::leaveRoom(player_ptr player) {

    bool removed = false;
    if (whitePlayer_ == player) {
        whitePlayer_ = nullptr;
        removed = true;
    } else if (blackPlayer_ == player) {
        blackPlayer_ = nullptr;
        removed = true;
    }

    if (removed) {
        if (whitePlayer_ != nullptr) {
            Server::getInstance()->putMessageInQueue(
                    std::make_shared<OpponentLeftRoomSignal>(whitePlayer_->getConnectionProtocolHandler())
            );
        } else if (blackPlayer_ != nullptr) {
            Server::getInstance()->putMessageInQueue(
                    std::make_shared<OpponentLeftRoomSignal>(blackPlayer_->getConnectionProtocolHandler())
            );
        }

        player->setRoom(-1);
        --numberOfPlayers_;
    }

    if (numberOfPlayers_ <= 0) {
        RoomManager::getInstance()->deleteRoom(this);
    }

    return removed;

}

void Room::playerWon(PlayerColour colour) {

    player_ptr won;
    player_ptr lost;

    if (colour == PlayerColour::white) {
        won = whitePlayer_;
        lost = blackPlayer_;
    } else {
        won = blackPlayer_;
        lost = whitePlayer_;
    }

    Server::getInstance()->putMessageInQueue(
            std::make_shared<GameEndSignal>(won->getConnectionProtocolHandler(), true)
    );

    Server::getInstance()->putMessageInQueue(
            std::make_shared<GameEndSignal>(lost->getConnectionProtocolHandler(), false)
    );

}

const int Room::getRoomID() const{
    return roomID_;
}

void Room::startNewGame() {

    if (numberOfPlayers_ != 2) return;

    game_.startGame();
    game_.setGameObserver(this);

    Server::getInstance()->putMessageInQueue(
            std::make_shared<BoardSignal>(whitePlayer_->getConnectionProtocolHandler(), game_.getBoard(PlayerColour::white), true,"white")
    );

    Server::getInstance()->putMessageInQueue(
            std::make_shared<BoardSignal>(blackPlayer_->getConnectionProtocolHandler(), game_.getBoard(PlayerColour::black), false,"black")
    );

}

void Room::makeMove(const std::vector<Point> &move, Room::player_ptr player) {

    PlayerColour playerColour = player == whitePlayer_ ? PlayerColour::white : PlayerColour::black;

    game_.makeMove(playerColour, move);

    Server::getInstance()->putMessageInQueue(
            std::make_shared<BoardSignal>(whitePlayer_->getConnectionProtocolHandler(), game_.getBoard(PlayerColour::white),
                                          game_.whoseTurn() == PlayerColour::white,"white")
    );

    Server::getInstance()->putMessageInQueue(
            std::make_shared<BoardSignal>(blackPlayer_->getConnectionProtocolHandler(), game_.getBoard(PlayerColour::black),
                                          game_.whoseTurn() == PlayerColour::black,"black")
    );

}

void Room::sendTextMessage(Room::player_ptr sender, const std::string &message) {

    player_ptr receiver = sender == whitePlayer_ ? blackPlayer_ : whitePlayer_;

    if (receiver == nullptr) {
        Server::getInstance()->putMessageInQueue(
                std::make_shared<TextMessage>(sender->getConnectionProtocolHandler(), "Message was lost due to the lack of an opponent.")
        );
    }

    else{
        Server::getInstance()->putMessageInQueue(
                std::make_shared<TextMessage>(receiver->getConnectionProtocolHandler(), message)
        );
    }


}


