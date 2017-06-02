//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEOBSERVER_HPP
#define ZPR_DRAUGHTS_GAMEOBSERVER_HPP

#include "GameLogic/PlayerColour.hpp"

class Player;

class GameObserver {
public:

    virtual void playerWon(PlayerColour) =  0;

    virtual ~GameObserver() {}
};


#endif //ZPR_DRAUGHTS_GAMEOBSERVER_HPP
