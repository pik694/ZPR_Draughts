//
// Created by Piotr Żelazko on 23.04.2017.
//

#include <memory>

#include <Signals/PermissionSignal.hpp>
#include "MessageDispatcher.hpp"
#include "Server.hpp"
#include "RoomManager.hpp"
#include "PlayerManager.hpp"


void MessageDispatcher::dispatch(EnterRoomSignal& enterRoomSignal) {

    Room* room = RoomManager::getInstance()->getRoom(enterRoomSignal.getRoomID());
    Player* player = PlayerManager::getInstance()->getPlayer(enterRoomSignal.getConnectionProtocolHandler());

    if (player == nullptr) throw std::invalid_argument("Could not find such a player");

    bool answer = false;

    if (room != nullptr && room->joinRoom(player)) {
        answer = true;
    }

    std::shared_ptr<Signal> signal = std::make_shared<PermissionSignal>(enterRoomSignal.getConnectionProtocolHandler(), answer);

    Server::getInstance()->putMessageInQueue(signal);

}


void MessageDispatcher::dispatch(LeaveRoomSignal& leaveRoomSignal) {

    Player* player = PlayerManager::getInstance()->getPlayer(leaveRoomSignal.getConnectionProtocolHandler());

    if (player != nullptr){

    }

}

void MessageDispatcher::dispatch(NewGameSignal &) {
    throw std::runtime_error("Not implemented yet");
}

void MessageDispatcher::dispatch(NewRoomRequestSignal& ) {



}

void MessageDispatcher::dispatch(NickRequestSignal& nickRequest) {

    bool answer = false;

    if (Server::getInstance()->validateNick(nickRequest.getNick())){
        answer = true;

        Server::getInstance()->addPlayer(nickRequest.getNick(), nickRequest.getConnectionProtocolHandler());
    }


    std::shared_ptr<Signal> signal = std::make_shared<PermissionSignal>(nickRequest.getConnectionProtocolHandler(), answer);

    Server::getInstance()->putMessageInQueue(signal);

}

void MessageDispatcher::dispatch(TextMessage& textMessage) {

    Player* player = PlayerManager::getInstance()->getPlayer(textMessage.getConnectionProtocolHandler());

    if (player == nullptr) throw std::invalid_argument("Could not find such a player");

    Room* room = RoomManager::getInstance()->getRoom(player->getRoom());

    if (room != nullptr){
        room->sendTextMessage(player, textMessage.getMessage());
    }

}


