//
// Created by Piotr Żelazko on 23.04.2017.
//

#include <memory>

#include <Signals/PermissionSignal.hpp>
#include "MessageDispatcher.hpp"
#include "Server.hpp"




void MessageDispatcher::dispatch(EnterRoomSignal &) {
    throw std::runtime_error("Not implemented yet");
}


void MessageDispatcher::dispatch(LeaveRoomSignal &) {
    throw std::runtime_error("Not implemented yet");
}

void MessageDispatcher::dispatch(NewGameSignal &) {
    throw std::runtime_error("Not implemented yet");
}

void MessageDispatcher::dispatch(NewRoomRequestSignal &) {
    throw std::runtime_error("Not implemented yet");
}

void MessageDispatcher::dispatch(NickRequestSignal& nickRequest) {

    bool answer = false;

    if (Server::getInstance()->validateNick(nickRequest.getNick())){
            answer = true;
        Server::getInstance()->addPlayer(nickRequest.getNick(), nullptr); //TODO
    }


    std::shared_ptr<Signal> signal = std::make_shared<PermissionSignal>(nickRequest.getConnectionProtocolHandler(), answer);

    Server::getInstance()->putMessageInQueue(signal);

}

void MessageDispatcher::dispatch(TextMessage &) {
    throw std::runtime_error("Not implemented yet");
}


