

set(SOURCE_FILES Player.cpp PlayerManager.cpp ConnectionProtocolHandler.cpp GameLogic/Game.cpp Room.cpp RoomManager.cpp Server.cpp main.cpp GameLogic/Point.hpp GameObserver.hpp GameLogic/Board.cpp GameLogic/Board.hpp GameLogic/PieceKind.hpp MessageDispatcher.cpp MessageDispatcher.hpp GameLogic/PlayerColour.hpp Signals/Signal.hpp Signals/TextMessage.hpp Signals/BoardSignal.hpp Signals/EnterRoomSignal.hpp Signals/GameEndSignal.hpp Signals/LeaveRoomSignal.hpp Signals/NewGameSignal.hpp Signals/OpponentEnteredTheRoomSignal.hpp Signals/NewRoomRequestSignal.hpp Signals/OpponentLeftRoomSignal.hpp Signals/PermissionSignal.hpp Signals/NickRequestSignal.hpp Signals/EnterRoomSignal.cpp Signals/BoardSignal.cpp Signals/LeaveRoomSignal.cpp Signals/NewGameSignal.cpp Signals/NewRoomRequestSignal.cpp Signals/NickRequestSignal.cpp Signals/TextMessage.cpp Signals/SignalFactory.hpp Signals/StaticInit.cpp Signals/OpponentEnteredTheRoomSignal.cpp Signals/OpponentLeftRoomSignal.cpp Signals/PermissionSignal.cpp Signals/GameEndSignal.cpp Signals/Signal.cpp Signals/MoveSignal.cpp Signals/MoveSignal.hpp Signals/RoomsRequestSignal.cpp Signals/RoomsRequestSignal.hpp Signals/RoomsSignal.cpp Signals/RoomsSignal.hpp Signals/SendSignalDelegate.cpp Signals/SendSignalDelegate.hpp ../tests/Helpers/TestConnectionProtocolHandler.cpp ../tests/Helpers/TestSignalSendDelegate.cpp)


add_executable(ZPR_Draughts ${SOURCE_FILES})
find_package(Boost COMPONENTS system REQUIRED)

if (APPLE)
    set(JSONCPP_LIBRARY_DIR /usr/local/lib/libjsoncpp.dylib)
    target_link_libraries(ZPR_Draughts ${Boost_SYSTEM_LIBRARY} ${JSONCPP_LIBRARY_DIR})

else ()
    target_link_libraries(ZPR_Draughts ${Boost_SYSTEM_LIBRARY} jsoncpp pthread)
endif ()


if (_ENABLE_TESTS_AT_EACH_BUILD_)
    add_dependencies(ZPR_Draughts runTests)
endif ()