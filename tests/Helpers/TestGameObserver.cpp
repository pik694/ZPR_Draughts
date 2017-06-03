//
// Created by Piotr Żelazko on 02.06.2017.
//

#include "TestGameObserver.hpp"

PlayerColour TestGameObserver::whoWon(){
    return whoWon_;
}

bool TestGameObserver::hasSomebodyWon(){
    return somebodyWon_;
}

void TestGameObserver::playerWon(PlayerColour player){
    somebodyWon_ = true;
    whoWon_ = player;
}

