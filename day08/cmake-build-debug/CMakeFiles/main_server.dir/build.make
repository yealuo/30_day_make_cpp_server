# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/yeluo/.cache/JetBrains/RemoteDev/dist/2353c1ea5e0fc_CLion-2024.1.2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/yeluo/.cache/JetBrains/RemoteDev/dist/2353c1ea5e0fc_CLion-2024.1.2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_server.dir/flags.make

CMakeFiles/main_server.dir/main_server.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/main_server.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/main_server.cpp
CMakeFiles/main_server.dir/main_server.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_server.dir/main_server.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/main_server.cpp.o -MF CMakeFiles/main_server.dir/main_server.cpp.o.d -o CMakeFiles/main_server.dir/main_server.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/main_server.cpp

CMakeFiles/main_server.dir/main_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/main_server.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/main_server.cpp > CMakeFiles/main_server.dir/main_server.cpp.i

CMakeFiles/main_server.dir/main_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/main_server.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/main_server.cpp -o CMakeFiles/main_server.dir/main_server.cpp.s

CMakeFiles/main_server.dir/src/Acceptor.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/Acceptor.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Acceptor.cpp
CMakeFiles/main_server.dir/src/Acceptor.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main_server.dir/src/Acceptor.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/Acceptor.cpp.o -MF CMakeFiles/main_server.dir/src/Acceptor.cpp.o.d -o CMakeFiles/main_server.dir/src/Acceptor.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Acceptor.cpp

CMakeFiles/main_server.dir/src/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/Acceptor.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Acceptor.cpp > CMakeFiles/main_server.dir/src/Acceptor.cpp.i

CMakeFiles/main_server.dir/src/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/Acceptor.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Acceptor.cpp -o CMakeFiles/main_server.dir/src/Acceptor.cpp.s

CMakeFiles/main_server.dir/src/Channel.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/Channel.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Channel.cpp
CMakeFiles/main_server.dir/src/Channel.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main_server.dir/src/Channel.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/Channel.cpp.o -MF CMakeFiles/main_server.dir/src/Channel.cpp.o.d -o CMakeFiles/main_server.dir/src/Channel.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Channel.cpp

CMakeFiles/main_server.dir/src/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/Channel.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Channel.cpp > CMakeFiles/main_server.dir/src/Channel.cpp.i

CMakeFiles/main_server.dir/src/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/Channel.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Channel.cpp -o CMakeFiles/main_server.dir/src/Channel.cpp.s

CMakeFiles/main_server.dir/src/Connection.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/Connection.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Connection.cpp
CMakeFiles/main_server.dir/src/Connection.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main_server.dir/src/Connection.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/Connection.cpp.o -MF CMakeFiles/main_server.dir/src/Connection.cpp.o.d -o CMakeFiles/main_server.dir/src/Connection.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Connection.cpp

CMakeFiles/main_server.dir/src/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/Connection.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Connection.cpp > CMakeFiles/main_server.dir/src/Connection.cpp.i

CMakeFiles/main_server.dir/src/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/Connection.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Connection.cpp -o CMakeFiles/main_server.dir/src/Connection.cpp.s

CMakeFiles/main_server.dir/src/Epoll.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/Epoll.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Epoll.cpp
CMakeFiles/main_server.dir/src/Epoll.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main_server.dir/src/Epoll.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/Epoll.cpp.o -MF CMakeFiles/main_server.dir/src/Epoll.cpp.o.d -o CMakeFiles/main_server.dir/src/Epoll.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Epoll.cpp

CMakeFiles/main_server.dir/src/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/Epoll.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Epoll.cpp > CMakeFiles/main_server.dir/src/Epoll.cpp.i

CMakeFiles/main_server.dir/src/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/Epoll.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Epoll.cpp -o CMakeFiles/main_server.dir/src/Epoll.cpp.s

CMakeFiles/main_server.dir/src/EventLoop.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/EventLoop.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/EventLoop.cpp
CMakeFiles/main_server.dir/src/EventLoop.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main_server.dir/src/EventLoop.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/EventLoop.cpp.o -MF CMakeFiles/main_server.dir/src/EventLoop.cpp.o.d -o CMakeFiles/main_server.dir/src/EventLoop.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/EventLoop.cpp

CMakeFiles/main_server.dir/src/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/EventLoop.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/EventLoop.cpp > CMakeFiles/main_server.dir/src/EventLoop.cpp.i

CMakeFiles/main_server.dir/src/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/EventLoop.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/EventLoop.cpp -o CMakeFiles/main_server.dir/src/EventLoop.cpp.s

CMakeFiles/main_server.dir/src/InetAddress.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/InetAddress.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/InetAddress.cpp
CMakeFiles/main_server.dir/src/InetAddress.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main_server.dir/src/InetAddress.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/InetAddress.cpp.o -MF CMakeFiles/main_server.dir/src/InetAddress.cpp.o.d -o CMakeFiles/main_server.dir/src/InetAddress.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/InetAddress.cpp

CMakeFiles/main_server.dir/src/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/InetAddress.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/InetAddress.cpp > CMakeFiles/main_server.dir/src/InetAddress.cpp.i

CMakeFiles/main_server.dir/src/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/InetAddress.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/InetAddress.cpp -o CMakeFiles/main_server.dir/src/InetAddress.cpp.s

CMakeFiles/main_server.dir/src/Server.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/Server.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Server.cpp
CMakeFiles/main_server.dir/src/Server.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main_server.dir/src/Server.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/Server.cpp.o -MF CMakeFiles/main_server.dir/src/Server.cpp.o.d -o CMakeFiles/main_server.dir/src/Server.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Server.cpp

CMakeFiles/main_server.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/Server.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Server.cpp > CMakeFiles/main_server.dir/src/Server.cpp.i

CMakeFiles/main_server.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/Server.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Server.cpp -o CMakeFiles/main_server.dir/src/Server.cpp.s

CMakeFiles/main_server.dir/src/Socket.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/Socket.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Socket.cpp
CMakeFiles/main_server.dir/src/Socket.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main_server.dir/src/Socket.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/Socket.cpp.o -MF CMakeFiles/main_server.dir/src/Socket.cpp.o.d -o CMakeFiles/main_server.dir/src/Socket.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Socket.cpp

CMakeFiles/main_server.dir/src/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/Socket.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Socket.cpp > CMakeFiles/main_server.dir/src/Socket.cpp.i

CMakeFiles/main_server.dir/src/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/Socket.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/Socket.cpp -o CMakeFiles/main_server.dir/src/Socket.cpp.s

CMakeFiles/main_server.dir/src/util.cpp.o: CMakeFiles/main_server.dir/flags.make
CMakeFiles/main_server.dir/src/util.cpp.o: /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/util.cpp
CMakeFiles/main_server.dir/src/util.cpp.o: CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main_server.dir/src/util.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_server.dir/src/util.cpp.o -MF CMakeFiles/main_server.dir/src/util.cpp.o.d -o CMakeFiles/main_server.dir/src/util.cpp.o -c /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/util.cpp

CMakeFiles/main_server.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/util.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/util.cpp > CMakeFiles/main_server.dir/src/util.cpp.i

CMakeFiles/main_server.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/util.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/src/util.cpp -o CMakeFiles/main_server.dir/src/util.cpp.s

# Object files for target main_server
main_server_OBJECTS = \
"CMakeFiles/main_server.dir/main_server.cpp.o" \
"CMakeFiles/main_server.dir/src/Acceptor.cpp.o" \
"CMakeFiles/main_server.dir/src/Channel.cpp.o" \
"CMakeFiles/main_server.dir/src/Connection.cpp.o" \
"CMakeFiles/main_server.dir/src/Epoll.cpp.o" \
"CMakeFiles/main_server.dir/src/EventLoop.cpp.o" \
"CMakeFiles/main_server.dir/src/InetAddress.cpp.o" \
"CMakeFiles/main_server.dir/src/Server.cpp.o" \
"CMakeFiles/main_server.dir/src/Socket.cpp.o" \
"CMakeFiles/main_server.dir/src/util.cpp.o"

# External object files for target main_server
main_server_EXTERNAL_OBJECTS =

main_server: CMakeFiles/main_server.dir/main_server.cpp.o
main_server: CMakeFiles/main_server.dir/src/Acceptor.cpp.o
main_server: CMakeFiles/main_server.dir/src/Channel.cpp.o
main_server: CMakeFiles/main_server.dir/src/Connection.cpp.o
main_server: CMakeFiles/main_server.dir/src/Epoll.cpp.o
main_server: CMakeFiles/main_server.dir/src/EventLoop.cpp.o
main_server: CMakeFiles/main_server.dir/src/InetAddress.cpp.o
main_server: CMakeFiles/main_server.dir/src/Server.cpp.o
main_server: CMakeFiles/main_server.dir/src/Socket.cpp.o
main_server: CMakeFiles/main_server.dir/src/util.cpp.o
main_server: CMakeFiles/main_server.dir/build.make
main_server: CMakeFiles/main_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable main_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_server.dir/build: main_server
.PHONY : CMakeFiles/main_server.dir/build

CMakeFiles/main_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_server.dir/clean

CMakeFiles/main_server.dir/depend:
	cd /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08 /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08 /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug /home/yeluo/project/C++/Internet_Programming/30_day_make_cpp_server/day08/cmake-build-debug/CMakeFiles/main_server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main_server.dir/depend

