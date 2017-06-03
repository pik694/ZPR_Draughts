//
// Created by Piotr Żelazko on 23.04.2017.
//

#include <memory>
#include "Signals/EnterRoomSignal.hpp"
#include "Signals/PermissionSignal.hpp"
#include "Signals/LeaveRoomSignal.hpp"
#include "Signals/NewGameSignal.hpp"
#include "Signals/NewRoomRequestSignal.hpp"
#include "Signals/RoomsRequestSignal.hpp"
#include "Signals/RoomsSignal.hpp"
#include "Signals/MoveSignal.hpp"
#include "Signals/TextMessage.hpp"
#include "Signals/NickRequestSignal.hpp"

#include "Player.hpp"
#include "PlayerManager.hpp"

#include "Room.hpp"
#include "RoomManager.hpp"
#include "Server.hpp"


void MessageDispatcher::dispatch(EnterRoomSignal &enterRoomSignal) {

    room_ptr room = RoomManager::getInstance()->getRoom(enterRoomSignal.getRoomID());
    player_ptr player = getPlayerFromSignal(&enterRoomSignal);

    bool answer = false;

    if (player->getRoom() == nullptr && room != nullptr && room->joinRoom(player)) {
        answer = true;
    }

    player->sendSignal(
            std::make_shared<PermissionSignal>(enterRoomSignal.getConnectionProtocolHandler(), answer,"EnterRoomSignal")
    );

}

void MessageDispatcher::dispatch(LeaveRoomSignal &leaveRoomSignal) {

    player_ptr player = getPlayerFromSignal(&leaveRoomSignal);

    if (player->getRoom() == nullptr || !player->getRoom()->leaveRoom(player))
        throw std::runtime_error("Unknown error appeared: could not exit form room");

}

void MessageDispatcher::dispatch(NewGameSignal &newGameSignal) {

    player_ptr player = getPlayerFromSignal(&newGameSignal);

    player->getRoom()->startNewGame();


}

void MessageDispatcher::dispatch(NewRoomRequestSignal &newRoomRequestSignal) {

    room_ptr newRoom;
    player_ptr player = getPlayerFromSignal(&newRoomRequestSignal);

    bool answer = true;
    try {
        newRoom = RoomManager::getInstance()->newRoom();
        newRoom->joinRoom(player);
    }
    catch (std::runtime_error e) {
        std::cerr << e.what() << std::endl;
        answer = false;
    }

    player->sendSignal(
            std::make_shared<PermissionSignal>(newRoomRequestSignal.getConnectionProtocolHandler(), answer,"NewRoomRequestSignal")
    );


}

void MessageDispatcher::dispatch(NickRequestSignal &nickRequest) {


    bool answer = false;

    if (PlayerManager::getInstance()->validateNick(nickRequest.getNick())) {
        answer = true;

        PlayerManager::getInstance()->addPlayer(nickRequest.getNick(), nickRequest.getConnectionProtocolHandler());
    }

    Server::getInstance()->putMessageInQueue(std::make_shared<PermissionSignal>(nickRequest.getConnectionProtocolHandler(), answer, "NickRequestSignal"));

}

void MessageDispatcher::dispatch(TextMessage &textMessage) {

    player_ptr player = getPlayerFromSignal(&textMessage);

    room_ptr room = player->getRoom();

    if (room != nullptr) {
        room->sendTextMessage(player, textMessage.getMessage());
    }

}

void MessageDispatcher::dispatch(MoveSignal &moveSignal) {

    player_ptr player = getPlayerFromSignal(&moveSignal);

    room_ptr room = player->getRoom();

    if (room != nullptr) {
        room->makeMove(moveSignal.getMove(), player);
    }

}

void MessageDispatcher::dispatch(RoomsRequestSignal& roomsRequestSignal) {

    std::vector<int> rooms = RoomManager::getInstance()->getRooms();

    player_ptr player = getPlayerFromSignal(&roomsRequestSignal);

    player->sendSignal(
        std::make_shared<RoomsSignal>(roomsRequestSignal.getConnectionProtocolHandler(), rooms,"RoomsRequestSignal")
    );


}

MessageDispatcher::player_ptr MessageDispatcher::getPlayerFromSignal(Signal* signal) {

    player_ptr player = PlayerManager::getInstance()->getPlayer(signal->getConnectionProtocolHandler());

    if (player == nullptr) throw std::invalid_argument("Could not find such a player");

    return player;

}


