#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

//#include <websocketpp/connection.hpp>

#include <thread>
#include <string>
#include <Signals/Signal.hpp>
#include <Signals/SendSignalDelegate.hpp>

class Room;

using websocketpp::connection_hdl;

class ConnectionProtocolHandler;

class Player {
    using room_ptr = std::shared_ptr<Room>;

public:

    Player();

    Player(std::string nick, ConnectionProtocolHandler *hdl, std::shared_ptr<SendSignalDelegate> delegate = std::make_shared<SendSignalDelegate>());

    void setNickName(std::string nick_a);

    void setRoom(int roomID);

    void setRoom(room_ptr room);

    int getRoomID();

    room_ptr getRoom();

    std::string getName();

    void sendSignal(std::shared_ptr<Signal>);

    ConnectionProtocolHandler *getConnectionProtocolHandler();

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