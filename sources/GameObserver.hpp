//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEOBSERVER_HPP
#define ZPR_DRAUGHTS_GAMEOBSERVER_HPP

/*! @file
 *  @brief Interface that enables a class to be informed when a game finishes.
 */

#include "GameLogic/PlayerColour.hpp"

class Player;


/*!
 *  @brief Interface that enables a class to be informed when a game finishes.
 */
class GameObserver {
public:
    /*!
     * @brief method being called when an observed game finishes.
     */
    virtual void playerWon(PlayerColour) =  0;

    virtual ~GameObserver() {}
};


#endif //ZPR_DRAUGHTS_GAMEOBSERVER_HPP
