

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

set(TEST_SOURCES test_main.cpp CustomTests.cpp GameEngineTests.cpp)

add_executable(Tests  ${TEST_SOURCES})
target_link_libraries(Tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

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
