//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEOBSERVER_HPP
#define ZPR_DRAUGHTS_GAMEOBSERVER_HPP

class Player;

class GameObserver {
public:

    virtual void playerWon(const Player*) = 0;

};


#endif //ZPR_DRAUGHTS_GAMEOBSERVER_HPP
