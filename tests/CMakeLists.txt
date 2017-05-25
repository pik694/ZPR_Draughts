
if(_ENABLE_TESTS_AT_EACH_BUILD_)
	find_package(Boost COMPONENTS unit_test_framework system REQUIRED)

	include_directories(../sources)
	include_directories(${Boost_INCLUDE_DIR})

	set(SOURCE_FILES
			../sources/Player.cpp ../sources/ClientManager.cpp ../sources/ConnectionProtocolHandler.cpp
			../sources/GameLogic/Game.cpp ../sources/Room.cpp ../sources/RoomManager.cpp ../sources/Server.cpp
			../sources/GameLogic/Point.hpp ../sources/GameObserver.hpp ../sources/GameLogic/Board.cpp
			../sources/GameLogic/Board.hpp ../sources/GameLogic/PieceKind.hpp ../sources/Message.cpp
			../sources/Message.hpp ../sources/MessageDispatcher.cpp
			../sources/MessageDispatcher.hpp ../sources/GameLogic/PlayerColour.hpp)

	set(TEST_SOURCES test_main.cpp CustomTests.cpp GameEngineTests.cpp)

	add_executable(Tests  ${TEST_SOURCES} ${SOURCE_FILES})
	target_link_libraries(Tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_SYSTEM_LIBRARY})


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