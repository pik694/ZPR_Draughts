//
// Created by Piotr Żelazko on 02.06.2017.
//

#ifndef ZPR_DRAUGHTS_TESTGAMEOBSERVER_HPP
#define ZPR_DRAUGHTS_TESTGAMEOBSERVER_HPP

#include "GameObserver.hpp"
#include "GameLogic/PlayerColour.hpp"

class TestGameObserver : public GameObserver{
public:

    TestGameObserver():somebodyWon_(false){}

    virtual void playerWon(PlayerColour player);

    PlayerColour whoWon();

    bool hasSomebodyWon();


private:

    bool somebodyWon_;
    PlayerColour whoWon_;

};


#endif //ZPR_DRAUGHTS_TESTGAMEOBSERVER_HPP
