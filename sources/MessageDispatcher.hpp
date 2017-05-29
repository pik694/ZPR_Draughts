//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
#define ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP


#include <Signals/Signal.hpp>
#include <Signals/EnterRoomSignal.hpp>
#include <Signals/LeaveRoomSignal.hpp>
#include <Signals/NewGameSignal.hpp>
#include <Signals/NewRoomRequestSignal.hpp>
#include <Signals/NickRequestSignal.hpp>
#include <Signals/TextMessage.hpp>

class MessageDispatcher {
public:

    void dispatch(EnterRoomSignal &);
    void dispatch(LeaveRoomSignal &);
    void dispatch(NewGameSignal &);
    void dispatch(NewRoomRequestSignal &);
    void dispatch(NickRequestSignal &);
    void dispatch(TextMessage &);

};


#endif //ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
