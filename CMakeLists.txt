cmake_minimum_required(VERSION 3.8)
project(ZPR_Draughts)



include(CTest)
enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/sources")

set(CMAKE_CXX_STANDARD 14)


set(_ENABLE_TESTS_AT_EACH_BUILD_ ON) # to disable set to OFF

add_subdirectory(sources)
add_subdirectory(tests)