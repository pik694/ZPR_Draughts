#include "Player.hpp"
#include "ConnectionProtocolHandler.hpp"
#include "RoomManager.hpp"
#include "Room.hpp"

using room_ptr = std::shared_ptr<Room>;

int Player::clientIds_ = 0;


Player::Player() : clientID_(clientIds_++), connectionProtocolHandler_(nullptr) {
    //TODO: throw std::runtime_error("This constructor should not be invoked");
}

Player::Player(std::string nick, ConnectionProtocolHandler *hdl, std::shared_ptr<SendSignalDelegate> delegate) :
        clientID_(clientIds_++),
        nickname_(nick),
        connectionProtocolHandler_(hdl),
        delegate_(delegate) {}


Player::~Player() {

    if (room_.get() != nullptr){
        room_->leaveRoom(shared_from_this());
    }

}

void Player::setNickName(std::string nick_a) {
    nickname_ = nick_a;
}

bool Player::setRoom(room_ptr room) {

    if (room != nullptr && room_ != nullptr) return false;

    room_ = room;
    return true;
}

void Player::resetRoom() {
    room_ = nullptr;
}


room_ptr Player::getRoom() {
    return room_;
}

std::string Player::getNick() {
    return nickname_;
}


ConnectionProtocolHandler *Player::getConnectionProtocolHandler() {
    return connectionProtocolHandler_;
}

void Player::sendSignal(std::shared_ptr<Signal> signal) {
    delegate_->sendSignal(signal);
}
