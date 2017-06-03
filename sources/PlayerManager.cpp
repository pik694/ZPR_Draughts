//
// Created by Piotr Żelazko on 30.05.2017.
//

#include "PlayerManager.hpp"
#include "RoomManager.hpp"
#include "Player.hpp"
#include "Room.hpp"

PlayerManager *PlayerManager::instance_ = nullptr;


PlayerManager *PlayerManager::getInstance() {

    if (instance_ == nullptr) {
        instance_ = new PlayerManager();
    }

    return instance_;
}

bool PlayerManager::validateNick(std::string nick) {

    if (nick.length() == 0) return false;

    for (auto player : players_) {
        if (player.second->getNick() == nick) return false;
    }

    return true;
}

void PlayerManager::addPlayer(std::string nick, ConnectionProtocolHandler *hdl) {

    if (validateNick(nick)) players_[hdl] = std::make_shared<Player>(nick, hdl);
}

void PlayerManager::removePlayer(ConnectionProtocolHandler *hdl) {

    if(players_.find(hdl) == players_.end())
        return;

    player_ptr toBeRemoved = players_[hdl];

    if(toBeRemoved == nullptr)
        return;

    players_.erase(hdl);

    if(toBeRemoved->getRoom() != nullptr)
        toBeRemoved->getRoom()->leaveRoom(toBeRemoved);

}

PlayerManager::player_ptr PlayerManager::getPlayer(ConnectionProtocolHandler *hdl) {

    return players_[hdl];

}



PlayerManager::PlayerManager() {}







