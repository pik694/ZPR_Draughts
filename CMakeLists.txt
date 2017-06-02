cmake_minimum_required(VERSION 3.7)
project(ZPR_Draughts)




include(CTest)
enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/sources")

set(CMAKE_CXX_STANDARD 14)

if (APPLE)
    include_directories(/usr/local/include/)

elseif (WIN32)
    link_directories("C:/local/boost_1_64_0/lib64-msvc-14.0")
	include_directories("C:/local/boost_1_64_0/boost")

	# needed for cmake to find boost libraries
	SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/local/boost_1_64_0")
	SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/local/boost_1_64_0/lib64-msvc-14.0")

	SET(Boost_USE_STATIC_LIBS ON) # otherwise visual studio tries to link to dll libraries

elseif (UNIX)
    include_directories() # add paths to libraries on Unix
endif()

set(_ENABLE_TESTS_AT_EACH_BUILD_ ON) # to disable set to OFF



add_subdirectory(sources)
add_subdirectory(tests)
