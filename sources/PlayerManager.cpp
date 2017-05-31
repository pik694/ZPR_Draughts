//
// Created by Piotr Żelazko on 30.05.2017.
//

#include "PlayerManager.hpp"

PlayerManager *PlayerManager::instance_ = nullptr;


PlayerManager *PlayerManager::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new PlayerManager();
    }

    return instance_;
}

bool PlayerManager::validateNick(std::string nick) {

    for (auto player : players_) {
        if (player.second->getName() == nick) return false;
    }

    return true;
}

void PlayerManager::addPlayer(std::string nick, ConnectionProtocolHandler *hdl) {

    if (validateNick(nick)) players_[hdl] = std::make_shared<Player>(nick, hdl);
}

void PlayerManager::removePlayer(ConnectionProtocolHandler *hdl) {

    player_ptr toBeRemoved = players_[hdl];

    players_.erase(hdl);

    toBeRemoved->getRoom()->leaveRoom(toBeRemoved);

}

PlayerManager::player_ptr PlayerManager::getPlayer(ConnectionProtocolHandler *hdl) {

    return players_[hdl];

}

PlayerManager::PlayerManager() {}







