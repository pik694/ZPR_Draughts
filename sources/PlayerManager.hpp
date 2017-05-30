//
// Created by Piotr Żelazko on 30.05.2017.
//

#ifndef ZPR_DRAUGHTS_PLAYERMANAGER_HPP
#define ZPR_DRAUGHTS_PLAYERMANAGER_HPP


#include "../../../Desktop/sources/RoomManager.hpp"

class PlayerManager {
public:

    static PlayerManager* getInstance();

    Player* getPlayer(ConnectionProtocolHandler*);


    PlayerManager(const PlayerManager&) = delete;
private:
    static PlayerManager* instance_;

    PlayerManager();


};


#endif //ZPR_DRAUGHTS_PLAYERMANAGER_HPP
