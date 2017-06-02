//
// Created by Piotr Żelazko on 30.05.2017.
//

#ifndef ZPR_DRAUGHTS_PLAYERMANAGER_HPP
#define ZPR_DRAUGHTS_PLAYERMANAGER_HPP


#include "RoomManager.hpp"
#include "ConnectionProtocolHandler.hpp"

class PlayerManager {
    using player_ptr = std::shared_ptr<Player>;

public:

    static PlayerManager *getInstance();

    bool validateNick(std::string);

    void addPlayer(std::string nick, ConnectionProtocolHandler *hdl);

    player_ptr getPlayer(ConnectionProtocolHandler *);

    void removePlayer(ConnectionProtocolHandler *);

    PlayerManager(const PlayerManager &) = delete;

private:
    static PlayerManager *instance_;

    std::map<ConnectionProtocolHandler *, player_ptr> players_;

    PlayerManager();


};


#endif //ZPR_DRAUGHTS_PLAYERMANAGER_HPP
