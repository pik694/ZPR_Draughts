set(SOURCE_FILES Player.cpp ClientManager.cpp ConnectionProtocolHandler.cpp GameLogic/Game.cpp Room.cpp RoomManager.cpp Server.cpp main.cpp GameLogic/Point.hpp GameObserver.hpp GameLogic/Board.cpp GameLogic/Board.hpp GameLogic/PieceKind.hpp Message.cpp Message.hpp MessageDispatcher.cpp MessageDispatcher.hpp GameLogic/PlayerColour.hpp)

add_executable(ZPR_Draughts ${SOURCE_FILES})
find_package(Boost COMPONENTS system REQUIRED)

if(APPLE)
    set (JSONCPP_LIBRARY_DIR /usr/local/lib/libjsoncpp.dylib)
    target_link_libraries(ZPR_Draughts ${Boost_SYSTEM_LIBRARY} ${JSONCPP_LIBRARY_DIR})

else()
    target_link_libraries(ZPR_Draughts ${Boost_SYSTEM_LIBRARY} jsoncpp)
endif()


if (_ENABLE_TESTS_AT_EACH_BUILD_)
    add_dependencies(ZPR_Draughts runTests)
endif()