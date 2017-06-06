
if(_ENABLE_TESTS_AT_EACH_BUILD_)
	find_package(Boost COMPONENTS unit_test_framework system REQUIRED)

	include_directories(../sources)
	include_directories(${Boost_INCLUDE_DIR})



	set(SOURCE_FILES
			../sources/Player.cpp
			../sources/PlayerManager.cpp
			../sources/ConnectionProtocolHandler.cpp
			../sources/GameLogic/Game.cpp
			../sources/Room.cpp
			../sources/RoomManager.cpp
			../sources/Server.cpp
			../sources/GameLogic/Point.hpp
			../sources/GameObserver.hpp
			../sources/GameLogic/Board.cpp
			../sources/GameLogic/Board.hpp
			../sources/GameLogic/PieceKind.hpp
			../sources/MessageDispatcher.cpp
			../sources/MessageDispatcher.hpp
			../sources/GameLogic/PlayerColour.hpp
			../sources/Signals/Signal.hpp
			../sources/Signals/TextMessage.hpp
			../sources/Signals/BoardSignal.hpp
			../sources/Signals/EnterRoomSignal.hpp
			../sources/Signals/GameEndSignal.hpp
			../sources/Signals/LeaveRoomSignal.hpp
			../sources/Signals/NewGameSignal.hpp
			../sources/Signals/OpponentEnteredTheRoomSignal.hpp
			../sources/Signals/NewRoomRequestSignal.hpp
			../sources/Signals/OpponentLeftRoomSignal.hpp
			../sources/Signals/PermissionSignal.hpp
			../sources/Signals/NickRequestSignal.hpp
			../sources/Signals/EnterRoomSignal.cpp
			../sources/Signals/BoardSignal.cpp
			../sources/Signals/LeaveRoomSignal.cpp
			../sources/Signals/NewGameSignal.cpp
			../sources/Signals/NewRoomRequestSignal.cpp
			../sources/Signals/NickRequestSignal.cpp
			../sources/Signals/TextMessage.cpp
			../sources/Signals/SignalFactory.hpp
			../sources/Signals/StaticInit.cpp
			../sources/Signals/OpponentEnteredTheRoomSignal.cpp
			../sources/Signals/OpponentLeftRoomSignal.cpp
			../sources/Signals/PermissionSignal.cpp
			../sources/Signals/GameEndSignal.cpp
			../sources/Signals/Signal.cpp
			../sources/Signals/MoveSignal.cpp
			../sources/Signals/MoveSignal.hpp
            ../sources/Signals/SendSignalDelegate.cpp
			../sources/Signals/SendSignalDelegate.hpp
			../sources/Signals/RoomsRequestSignal.cpp
			../sources/Signals/RoomsRequestSignal.hpp
			../sources/Signals/RoomsSignal.cpp
			../sources/Signals/RoomsSignal.hpp
			Helpers/TestSignalSendDelegate.cpp
			Helpers/TestSignalSendDelegate.hpp)

	set(TEST_SOURCES test_main.cpp GameEngineTests.cpp Helpers/TestConnectionProtocolHandler.cpp Helpers/TestConnectionProtocolHandler.hpp RoomTests.cpp Helpers/TestGameObserver.cpp Helpers/TestGameObserver.hpp PlayerManagerTests.cpp PlayerTests.cpp RoomManagerTests.cpp)

	add_executable(Tests  ${TEST_SOURCES} ${SOURCE_FILES})
	target_link_libraries(Tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_SYSTEM_LIBRARY})

	if (APPLE)
		set(JSONCPP_LIBRARY_DIR /usr/local/lib/libjsoncpp.dylib)
		target_link_libraries(Tests ${Boost_SYSTEM_LIBRARY} ${JSONCPP_LIBRARY_DIR})

	elseif (UNIX)
		target_link_libraries(Tests ${Boost_SYSTEM_LIBRARY} jsoncpp pthread)
	elseif(WIN32)
		include_directories("C:/local/jsoncpp-master/include")
		include_directories("C:/local/websocketpp-master")
		include_directories("C:/local/boost_1_64_0")
		set(JSONCPP_LIBRARY_DIR C:/local/jsoncpp-master/makefiles/msvc2010/Release/lib_json.lib)
		target_link_libraries(Tests ${Boost_SYSTEM_LIBRARY} ${JSONCPP_LIBRARY_DIR})
	endif ()



	add_test(boostUnitTestsRun Tests)

	if (CMAKE_CONFIGURATION_TYPES)
	    add_custom_target(runTests COMMAND ${CMAKE_CTEST_COMMAND}
	            --force-new-ctest-process --output-on-failure
	            --build-config "$<CONFIGURATION>"
	            DEPENDS Tests)
	else()
	    add_custom_target(runTests COMMAND ${CMAKE_CTEST_COMMAND}
	            --force-new-ctest-process --output-on-failure
	            DEPENDS Tests)
	endif()
endif()