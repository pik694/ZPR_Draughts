#include "ConnectionProtocolHandler.hpp"

#include "Server.hpp"
#include "RoomManager.hpp"
#include "PlayerManager.hpp"
#include "Action.hpp"
#include "MessageDispatcher.hpp"
#include "Signals/Signal.hpp"
#include "Signals/NickRequestSignal.hpp"
#include "Signals/BoardSignal.hpp"
#include "Signals/SignalFactory.hpp"

using websocketpp::connection_hdl;
using websocketpp::lib::thread;
using websocketpp::lib::lock_guard;
using websocketpp::lib::unique_lock;

ConnectionProtocolHandler::ConnectionProtocolHandler(connection_hdl &con) {
    //throw std::runtime_error("Not implemented yet");
    currentConnection_ = con;
    state_ = ConnectionStates::JUST_STARTED;
}
connection_hdl ConnectionProtocolHandler::getConnectionHdl() {
    return currentConnection_;
}
void ConnectionProtocolHandler::parseJson(std::string data) {
    //throw std::runtime_error("Not implemented yet");
    Json::Value root;
    std::stringstream myData(data);
    std::stringstream typeStream;
    myData >> root;
    //std::string myType = root.get("type","nothing").asString();

    Signal *currentSignal = SignalFactory::createInstance(root,this);
    if (currentSignal == nullptr) {
        //invalidRequest();
        std::cout << "not found sorry" << std::endl;
        return;
    }
    // TODO
    // weird bug it doesn't initialize in factory
    currentSignal->fillProtocolHandler(this);
    printf("INSIDE PARSE JSON %d\n",currentSignal->getConnectionProtocolHandler());
    currentSignal->acceptDispatcher(dispatcher_);
}


void testSession(std::string data) {

}


void ConnectionProtocolHandler::invalidRequest() {
    Json::Value jsonMessage;
    jsonMessage["type"] = "invalidRequest";
    std::stringstream myStream;
    myStream << jsonMessage;
    message_ptr msg;
    /*msg->set_payload(jsonMessage.asString());
    {
        lock_guard<mutex> guard(Server::m_action_lock);
        Server::m_actions.push(Action(MESSAGE,currentConnection_,msg));
    }
    Server::m_action_cond.notify_one();*/
}

void ConnectionProtocolHandler::onMessage(websocketpp::connection_hdl hdl, message_ptr msg) {
    currentConnection_ = hdl;
    std::cout << "Message: ";
    std::cout << msg->get_payload() << std::endl;
    std::cout<<msg->get_opcode()<<std::endl;
    parseJson(msg->get_payload());

    // TODO : should I call this method there ?
    // Server::getInstance()->putMessageInQueue(hdl, msg);

}

bool ConnectionProtocolHandler::tryToAssingName(const std::string &name) {
    throw std::runtime_error("Not implemented yet");
}
