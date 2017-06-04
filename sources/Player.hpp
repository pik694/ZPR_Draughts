#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <thread>
#include <string>

#include "Signals/Signal.hpp"
#include "Signals/SendSignalDelegate.hpp"

/*! @file
 *  @brief Player class represents a client connected to the server.
 *
 *  It encapsulates the ConnectionProtocolHandler through which communication takes place.
 */

class Room;
class ConnectionProtocolHandler;


using websocketpp::connection_hdl;



/*!
 *  @brief Player class represents a client connected to the server. It encapsulates the ConnectionProtocolHandler through which communication takes place.
 */
class Player : public std::enable_shared_from_this<Player>{
    using room_ptr = std::shared_ptr<Room>;
public:

    /*!
     * @deprecated this constructor should not be used.
     */
    Player();

    /*!
     * The only valid Player constructor.
     * @param nick
     * @param hdl
     * @param delegate object responsible for sending signals to the client.
     */
    Player(std::string nick, ConnectionProtocolHandler *hdl,
           std::shared_ptr<SendSignalDelegate> delegate = std::make_shared<SendSignalDelegate>());

    /*!
     * @deprecated
     * @param nick_a sets players nick
     */
    void setNickName(std::string nick_a);

    /*!
     * Tries to subscribe the player to the given room.
     * @param room Room to which player tries to subscribe.
     * @return Returns true if attempt was successfull.
     */
    bool setRoom(room_ptr room);

    /*!
     * Unsubscribes player from the room.
     * If player has not been assigned to any then does nothing.
     */
    void resetRoom();


    /*!
     *
     * @return room to which player is assigned.
     */
    room_ptr getRoom();

    /*!
     *
     * @return players nick
     */
    std::string getNick();

    /*!
     * Sends signal to the client.
     * Inside an instance of SendSignalDelegate is used.
     * This method was introduced in order to enable testing project properly.
     */
    void sendSignal(std::shared_ptr<Signal>);

    /*!
     *
     * @return Pointer to the ConnectionProtocolHandler connected with the player.
     */
    ConnectionProtocolHandler *getConnectionProtocolHandler();

    /*!
     * Default destructor
     */
    ~Player();

private:
    static int clientIds_;
    std::string nickname_;
    room_ptr room_;
    const int clientID_;
    ConnectionProtocolHandler *connectionProtocolHandler_;
    const std::shared_ptr<SendSignalDelegate> delegate_;

};

#endif // CLIENT_HPP