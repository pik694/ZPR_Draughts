#include "Player.hpp"
#include "ConnectionProtocolHandler.hpp"

using room_ptr = std::shared_ptr<Room>;

int Player::clientIds_ = 0;


Player::Player() : clientID_(clientIds_++), connectionProtocolHandler_(nullptr) {
    //TODO: throw std::runtime_error("This constructor should not be invoked");
}

Player::Player(std::string nick, ConnectionProtocolHandler *hdl) :
        clientID_(clientIds_++),
        nickname_(nick),
        connectionProtocolHandler_(hdl) {}


Player::~Player() {
}


void Player::setNickName(std::string nick_a) {
    nickname_ = nick_a;
}

void Player::setRoom(room_ptr room) {
    room_ = room;
}

void Player::setRoom(int roomID) {

    room_ = RoomManager::getInstance()->getRoom(roomID);

}

int Player::getRoomID() {

    return room_ != nullptr ? room_->getRoomID() : -1;

}

room_ptr Player::getRoom() {
    return room_;
}

std::string Player::getName() {
    return nickname_;
}


ConnectionProtocolHandler *Player::getConnectionProtocolHandler() {
    return connectionProtocolHandler_;
}
