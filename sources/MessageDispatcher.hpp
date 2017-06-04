//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
#define ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP

/*!
 * @file
 *
 * @brief Class responsible for dispatching messages.
 */

class Signal;
class EnterRoomSignal;
class LeaveRoomSignal;
class NewRoomRequestSignal;
class NewGameSignal;
class NickRequestSignal;
class TextMessage;
class MoveSignal;
class RoomsRequestSignal;

class Room;
class Player;


/*!
 * @brief Class responsible for dispatching messages.
 *
 * Uses Visitor design pattern and according to the type calls needed method.
 * According to the given Signal perform specific action.
 */
class MessageDispatcher {
public:

    /*!
     * @brief Tries to enter the room and sends answer.
     */
    void dispatch(EnterRoomSignal &);

    /*!
     * @brief Informs the server that the client left the room.
     * Throws exception when player was not in given room.
     * Does not send any answer.
     * Sends OpponentLeftTheRoomSignal to the opponent.
     */
    void dispatch(LeaveRoomSignal &);

    /*!
     * @brief Informs the room to which player is subscribed that he requests a start of a new game.
     * If game started then room sends BoardSignal to both players.
     */
    void dispatch(NewGameSignal &);

    /*!
     * @brief Sends to the RoomManager request about new room.
     * If RoomManager creates such, then the player is automatically subscribed to the new room.
     */
    void dispatch(NewRoomRequestSignal &);

    /*!
     * @brief Sends nick request to the PlayerManager,
     * if manager confirms then the nick is automatically given to the player.
     */
    void dispatch(NickRequestSignal &);

    /*!
     * @brief Sends text message to the players room.
     * If player is not subscribed to any room, then the message is lost.
     */
    void dispatch(TextMessage &);

    /*!
     * @brief Sends given move to the room.
     *
     * If move was made then the Room is responsible for sending BoardSignal which updates players boards.
     * If move was invalid there is no answer.
     */
    void dispatch(MoveSignal &);


    /*!
     * @brief Asks RoomManager about existing rooms.
     *
     * Sends answer with rooms given by RoomManager.
     */
    void dispatch(RoomsRequestSignal &);

private:
    using room_ptr = std::shared_ptr<Room>;
    using player_ptr = std::shared_ptr<Player>;

    player_ptr getPlayerFromSignal(Signal*);

};


#endif //ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
