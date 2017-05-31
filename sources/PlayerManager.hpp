//
// Created by Piotr Żelazko on 30.05.2017.
//

#ifndef ZPR_DRAUGHTS_PLAYERMANAGER_HPP
#define ZPR_DRAUGHTS_PLAYERMANAGER_HPP


#include "RoomManager.hpp"

class PlayerManager {
    using player_ptr = std::shared_ptr<Player>;

public:

    static PlayerManager* getInstance () {
		if (instance_ == nullptr){
			instance_ = new PlayerManager();
		}

		return instance_;
	}

    player_ptr getPlayer(ConnectionProtocolHandler*){throw std::runtime_error("Not implemented yet");}


    PlayerManager(const PlayerManager&) = delete;
private:
    static PlayerManager* instance_;

    PlayerManager(){throw std::runtime_error("Not implemented yet");}


};


#endif //ZPR_DRAUGHTS_PLAYERMANAGER_HPP
