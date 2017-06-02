//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
#define ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP


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



class MessageDispatcher {
public:

    void dispatch(EnterRoomSignal &);

    void dispatch(LeaveRoomSignal &);

    void dispatch(NewGameSignal &);

    void dispatch(NewRoomRequestSignal &);

    void dispatch(NickRequestSignal &);

    void dispatch(TextMessage &);

    void dispatch(MoveSignal &);

    void dispatch(RoomsRequestSignal &);

private:
    using room_ptr = std::shared_ptr<Room>;
    using player_ptr = std::shared_ptr<Player>;

    player_ptr getPlayerFromSignal(Signal*);

};


#endif //ZPR_DRAUGHTS_MESSAGEDISPATCHER_HPP
