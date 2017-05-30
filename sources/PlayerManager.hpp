//
// Created by Piotr Żelazko on 30.05.2017.
//

#ifndef ZPR_DRAUGHTS_PLAYERMANAGER_HPP
#define ZPR_DRAUGHTS_PLAYERMANAGER_HPP


#include "RoomManager.hpp"

class PlayerManager {
    using player_ptr = std::shared_ptr<Player>;

public:

    static PlayerManager* getInstance();

    player_ptr getPlayer(ConnectionProtocolHandler*);


    PlayerManager(const PlayerManager&) = delete;
private:
    static PlayerManager* instance_;

    PlayerManager();


};


#endif //ZPR_DRAUGHTS_PLAYERMANAGER_HPP
