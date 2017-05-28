//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
#define ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP

#include <iostream>
#include <Signals/BoardSignal.hpp>
#include <Signals/EnterRoomSignal.hpp>
#include <Signals/LeaveRoomSignal.hpp>
#include <Signals/NewRoomRequestSignal.hpp>
#include <Signals/NickRequestSignal.hpp>
#include <Signals/NewGameSignal.hpp>
#include <Signals/TextMessage.hpp>
#include "Signals/Signal.hpp"



class MessageDispatcher {
public:

    void visit (EnterRoomSignal&);
    void visit (LeaveRoomSignal&);
    void visit (NewGameSignal&);
    void visit (NewRoomRequestSignal&);
    void visit (NickRequestSignal&);
    void visit (TextMessage&);

};


#endif //ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
