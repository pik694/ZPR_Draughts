#ifndef ROOM_HPP
#define ROOM_HPP

/*!
 * @file
 * @brief Room is the place where the game takes place.
 *
 */

#include "GameObserver.hpp"
#include "GameLogic/Game.hpp"
#include "GameLogic/PlayerColour.hpp"

/*!
 * @brief Room is the place where the game takes place.
 *
 * Room keeps two players and a game.
 * This class is responsible for communication between clients and game, and also between two players (for example text messages).
 * Implements GameObserver interface so it can be informed when the game has finished and react properly.
 */
class Room : public GameObserver, public std::enable_shared_from_this<Room> {

    using player_ptr = std::shared_ptr<Player>;
public:

    /*!
     * @brief Default constructor.
     * @param ID new room's ID (it cannot be changed further on)
     */
    Room(int ID);

    /*!
     * @brief Tries to connect given player to the Room's instance.
     *
     * Checks whether player is connected somewhere an if there is free place in the room.
     * If there has been player inside, it informs both players about opponents nicks.
     * @return true if and only if given player has been properly assigned to the room.
     */
    bool joinRoom(player_ptr);

    /*!
     * @brief Unsubscribes given player from the room.
     *
     * Fails if given player has not been assigned to the room.
     * In case there is no player left, the room is removed.
     * If there still is player inside informs him about the fact that opponent has left.
     * @return true if and only if given player has been disconnected properly.
     */
    bool leaveRoom(player_ptr);

    /*!
     * @return Returns room's ID, given when creating the room.
     */
    const int getRoomID() const;

    /*!
     * @brief Method invoked by the game when one of the players has won.
     * Sends proper messages to the players.
     */
    void playerWon(PlayerColour);

    /*!
     * @brief Tries to start a new game.
     *
     * May fail if there is not players enough or when there already is a game in progress.
     * If succeeds, then sends BoardSignal to both players.
     * @return true if and only if new game has been started.
     */
    bool startNewGame();

    /*!
     * @brief Tries to make move.
     *
     * If succeeds then sends BoardSignal's to both players, else has no effect.
     */
    void makeMove(const std::vector<Point> &, player_ptr);

    /*!
     * @deprecated
     * @return true when there is only one player inside.
     */
    bool isOpponent();

    /*!
     * @brief Sends text message to the opponent.
     *
     * May fail when there is no opponent - message is lost, but proper message is sent to the sender.
     * Does not queue messages.
     */
    void sendTextMessage(player_ptr, const std::string &);

private:

    const int roomID_;

    player_ptr whitePlayer_;
    player_ptr blackPlayer_;

    int numberOfPlayers_;

    Game game_;

};

#endif // ROOM_HPP