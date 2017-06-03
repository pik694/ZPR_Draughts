#include "Signals/Signal.hpp"
#include "Signals/OpponentEnteredTheRoomSignal.hpp"
#include "Signals/GameEndSignal.hpp"
#include "Signals/BoardSignal.hpp"
#include "Signals/TextMessage.hpp"
#include "Signals/OpponentLeftRoomSignal.hpp"

#include "Player.hpp"
#include "Room.hpp"
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

    if (numberOfPlayers_ == 2 || !player->setRoom(shared_from_this())) return false;

    if (whitePlayer_ == nullptr) {
        whitePlayer_ = player;
    } else {
        blackPlayer_ = player;
    }

    if (numberOfPlayers_ == 1) {

        player_ptr opponent = player == whitePlayer_ ? blackPlayer_ : whitePlayer_;

        blackPlayer_->sendSignal(
                std::make_shared<OpponentEnteredTheRoomSignal>(blackPlayer_->getConnectionProtocolHandler(),
                                                               whitePlayer_->getNick())
        );

        whitePlayer_->sendSignal(
                std::make_shared<OpponentEnteredTheRoomSignal>(whitePlayer_->getConnectionProtocolHandler(),
                                                               blackPlayer_->getNick())
        );
    }

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

        game_.stopGame();

        if (whitePlayer_ != nullptr) {
            whitePlayer_->sendSignal(
                    std::make_shared<OpponentLeftRoomSignal>(whitePlayer_->getConnectionProtocolHandler())
            );
        } else if (blackPlayer_ != nullptr) {
            blackPlayer_->sendSignal(
                    std::make_shared<OpponentLeftRoomSignal>(blackPlayer_->getConnectionProtocolHandler())
            );
        }

        player->resetRoom();
        --numberOfPlayers_;
    }

    if (numberOfPlayers_ <= 0) {
        RoomManager::getInstance()->deleteRoom(shared_from_this());
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

    won->sendSignal(
            std::make_shared<GameEndSignal>(won->getConnectionProtocolHandler(), true)
    );

    lost->sendSignal(
            std::make_shared<GameEndSignal>(lost->getConnectionProtocolHandler(), false)
    );

}

const int Room::getRoomID() const{
    return roomID_;
}

bool Room::startNewGame() {

    if (numberOfPlayers_ != 2) return false;

    game_.startGame();
    game_.setGameObserver(this);

    whitePlayer_->sendSignal(
            std::make_shared<BoardSignal>(whitePlayer_->getConnectionProtocolHandler(), game_.getBoard(PlayerColour::white), true,"white")
    );

    blackPlayer_->sendSignal(
            std::make_shared<BoardSignal>(blackPlayer_->getConnectionProtocolHandler(), game_.getBoard(PlayerColour::black), false,"black")
    );

    return true;

}

void Room::makeMove(const std::vector<Point> &move, Room::player_ptr player) {

    PlayerColour playerColour = player == whitePlayer_ ? PlayerColour::white : PlayerColour::black;

    if (!game_.isInProcess() || numberOfPlayers_ != 2) return;

    game_.makeMove(playerColour, move);

    whitePlayer_->sendSignal(
            std::make_shared<BoardSignal>(whitePlayer_->getConnectionProtocolHandler(), game_.getBoard(PlayerColour::white),
                                          game_.whoseTurn() == PlayerColour::white,"white")
    );

    blackPlayer_->sendSignal(
            std::make_shared<BoardSignal>(blackPlayer_->getConnectionProtocolHandler(), game_.getBoard(PlayerColour::black),
                                          game_.whoseTurn() == PlayerColour::black,"black")
    );

}

void Room::sendTextMessage(Room::player_ptr sender, const std::string &message) {

    player_ptr receiver = nullptr;

    if (sender == whitePlayer_){
        receiver = blackPlayer_;
    }
    else if (sender == blackPlayer_){
        receiver = whitePlayer_;
    }


    if (receiver == nullptr) {
        sender->sendSignal(
                std::make_shared<TextMessage>(sender->getConnectionProtocolHandler(), "Message was lost.")
        );
    }

    else{
        receiver->sendSignal(
                std::make_shared<TextMessage>(receiver->getConnectionProtocolHandler(), message)
        );
    }


}


