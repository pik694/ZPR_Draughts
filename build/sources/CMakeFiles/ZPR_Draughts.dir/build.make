# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/john/checkers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/john/checkers/build

# Include any dependencies generated for this target.
include sources/CMakeFiles/ZPR_Draughts.dir/depend.make

# Include the progress variables for this target.
include sources/CMakeFiles/ZPR_Draughts.dir/progress.make

# Include the compile flags for this target's objects.
include sources/CMakeFiles/ZPR_Draughts.dir/flags.make

sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o: ../sources/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/Player.cpp.o -c /home/john/checkers/sources/Player.cpp

sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/Player.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/Player.cpp > CMakeFiles/ZPR_Draughts.dir/Player.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/Player.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/Player.cpp -o CMakeFiles/ZPR_Draughts.dir/Player.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o: ../sources/ClientManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o -c /home/john/checkers/sources/ClientManager.cpp

sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/ClientManager.cpp > CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/ClientManager.cpp -o CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o: ../sources/ConnectionProtocolHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o -c /home/john/checkers/sources/ConnectionProtocolHandler.cpp

sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/ConnectionProtocolHandler.cpp > CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/ConnectionProtocolHandler.cpp -o CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o: ../sources/GameLogic/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o -c /home/john/checkers/sources/GameLogic/Game.cpp

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/GameLogic/Game.cpp > CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/GameLogic/Game.cpp -o CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o: ../sources/Room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/Room.cpp.o -c /home/john/checkers/sources/Room.cpp

sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/Room.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/Room.cpp > CMakeFiles/ZPR_Draughts.dir/Room.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/Room.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/Room.cpp -o CMakeFiles/ZPR_Draughts.dir/Room.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o: ../sources/RoomManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o -c /home/john/checkers/sources/RoomManager.cpp

sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/RoomManager.cpp > CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/RoomManager.cpp -o CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o: ../sources/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/Server.cpp.o -c /home/john/checkers/sources/Server.cpp

sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/Server.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/Server.cpp > CMakeFiles/ZPR_Draughts.dir/Server.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/Server.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/Server.cpp -o CMakeFiles/ZPR_Draughts.dir/Server.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/main.cpp.o -c /home/john/checkers/sources/main.cpp

sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/main.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/main.cpp > CMakeFiles/ZPR_Draughts.dir/main.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/main.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/main.cpp -o CMakeFiles/ZPR_Draughts.dir/main.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o: ../sources/GameLogic/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o -c /home/john/checkers/sources/GameLogic/Board.cpp

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/GameLogic/Board.cpp > CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/GameLogic/Board.cpp -o CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o


sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o: sources/CMakeFiles/ZPR_Draughts.dir/flags.make
sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o: ../sources/MessageDispatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o"
	cd /home/john/checkers/build/sources && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o -c /home/john/checkers/sources/MessageDispatcher.cpp

sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.i"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/checkers/sources/MessageDispatcher.cpp > CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.i

sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.s"
	cd /home/john/checkers/build/sources && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/checkers/sources/MessageDispatcher.cpp -o CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.s

sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o.requires:

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o.requires

sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o.provides: sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o.requires
	$(MAKE) -f sources/CMakeFiles/ZPR_Draughts.dir/build.make sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o.provides.build
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o.provides

sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o.provides.build: sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o


# Object files for target ZPR_Draughts
ZPR_Draughts_OBJECTS = \
"CMakeFiles/ZPR_Draughts.dir/Player.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/Room.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/Server.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/main.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o" \
"CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o"

# External object files for target ZPR_Draughts
ZPR_Draughts_EXTERNAL_OBJECTS =

sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/build.make
sources/ZPR_Draughts: /usr/lib/x86_64-linux-gnu/libboost_system.so
sources/ZPR_Draughts: sources/CMakeFiles/ZPR_Draughts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/john/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable ZPR_Draughts"
	cd /home/john/checkers/build/sources && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ZPR_Draughts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sources/CMakeFiles/ZPR_Draughts.dir/build: sources/ZPR_Draughts

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/build

sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/Player.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/ClientManager.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/ConnectionProtocolHandler.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Game.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/Room.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/RoomManager.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/Server.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/main.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/GameLogic/Board.cpp.o.requires
sources/CMakeFiles/ZPR_Draughts.dir/requires: sources/CMakeFiles/ZPR_Draughts.dir/MessageDispatcher.cpp.o.requires

.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/requires

sources/CMakeFiles/ZPR_Draughts.dir/clean:
	cd /home/john/checkers/build/sources && $(CMAKE_COMMAND) -P CMakeFiles/ZPR_Draughts.dir/cmake_clean.cmake
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/clean

sources/CMakeFiles/ZPR_Draughts.dir/depend:
	cd /home/john/checkers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/john/checkers /home/john/checkers/sources /home/john/checkers/build /home/john/checkers/build/sources /home/john/checkers/build/sources/CMakeFiles/ZPR_Draughts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sources/CMakeFiles/ZPR_Draughts.dir/depend
