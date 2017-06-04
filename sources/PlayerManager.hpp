//
// Created by Piotr Żelazko on 30.05.2017.
//

#ifndef ZPR_DRAUGHTS_PLAYERMANAGER_HPP
#define ZPR_DRAUGHTS_PLAYERMANAGER_HPP

/*!
 * @file
 * @brief PlayerManager class is a singleton and keeps record of all the players and connected with them clients.
 */

#include "ConnectionProtocolHandler.hpp"


/*!
 * @brief Singleton that keeps instances of Player class.
 * It keeps players in a map where the key is a pointer to the ConnectionProtocolHandler connected with the client.
 */
class PlayerManager {
    using player_ptr = std::shared_ptr<Player>;

public:

    /*! @static
     * @return Returns valid pointer to the only instance of this class.
     */
    static PlayerManager *getInstance();


    /*!
     * Validates given nick - no two players can have the same nick at the same time.
     * @param nick nick to be checked
     * @return true if and only if the nick can be used.
     */
    bool validateNick(std::string nick);

    /*!
     * Creates and adds to the map instance of Player constructed with given parameters.
     * If nick validation returns false, this method will have no effect.
     * @param nick players nick
     * @param hdl ConnectionProtocolHandler connected with the client who the new player will represent.
     */
    void addPlayer(std::string nick, ConnectionProtocolHandler *hdl);


    /*!
     * @return Returns Player connected with the given ConnectionProtocolHandler.
     */
    player_ptr getPlayer(ConnectionProtocolHandler *);

    /*!
     * Removes player from the players list.
     * This method is responsible for unsigning the player from rooms and so on.
     */
    void removePlayer(ConnectionProtocolHandler *);

    /*!
     * @deprecated
     * Required when using a singleton design pattern.
     */
    PlayerManager(const PlayerManager &) = delete;

private:
    static PlayerManager *instance_;

    std::map<ConnectionProtocolHandler *, player_ptr> players_;

    PlayerManager();


};


#endif //ZPR_DRAUGHTS_PLAYERMANAGER_HPP
