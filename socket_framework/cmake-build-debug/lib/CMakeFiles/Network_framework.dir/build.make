# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/horson/Documents/V视频16/c++/socket_framework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug

# Include any dependencies generated for this target.
include lib/CMakeFiles/Network_framework.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/Network_framework.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/Network_framework.dir/flags.make

lib/CMakeFiles/Network_framework.dir/accepter.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/accepter.c.o: ../lib/accepter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/Network_framework.dir/accepter.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/accepter.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/accepter.c

lib/CMakeFiles/Network_framework.dir/accepter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/accepter.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/accepter.c > CMakeFiles/Network_framework.dir/accepter.c.i

lib/CMakeFiles/Network_framework.dir/accepter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/accepter.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/accepter.c -o CMakeFiles/Network_framework.dir/accepter.c.s

lib/CMakeFiles/Network_framework.dir/buffer.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/buffer.c.o: ../lib/buffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/CMakeFiles/Network_framework.dir/buffer.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/buffer.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/buffer.c

lib/CMakeFiles/Network_framework.dir/buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/buffer.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/buffer.c > CMakeFiles/Network_framework.dir/buffer.c.i

lib/CMakeFiles/Network_framework.dir/buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/buffer.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/buffer.c -o CMakeFiles/Network_framework.dir/buffer.c.s

lib/CMakeFiles/Network_framework.dir/channel.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/channel.c.o: ../lib/channel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/CMakeFiles/Network_framework.dir/channel.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/channel.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/channel.c

lib/CMakeFiles/Network_framework.dir/channel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/channel.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/channel.c > CMakeFiles/Network_framework.dir/channel.c.i

lib/CMakeFiles/Network_framework.dir/channel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/channel.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/channel.c -o CMakeFiles/Network_framework.dir/channel.c.s

lib/CMakeFiles/Network_framework.dir/channel_map.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/channel_map.c.o: ../lib/channel_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object lib/CMakeFiles/Network_framework.dir/channel_map.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/channel_map.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/channel_map.c

lib/CMakeFiles/Network_framework.dir/channel_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/channel_map.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/channel_map.c > CMakeFiles/Network_framework.dir/channel_map.c.i

lib/CMakeFiles/Network_framework.dir/channel_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/channel_map.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/channel_map.c -o CMakeFiles/Network_framework.dir/channel_map.c.s

lib/CMakeFiles/Network_framework.dir/event_loop.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/event_loop.c.o: ../lib/event_loop.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object lib/CMakeFiles/Network_framework.dir/event_loop.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/event_loop.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/event_loop.c

lib/CMakeFiles/Network_framework.dir/event_loop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/event_loop.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/event_loop.c > CMakeFiles/Network_framework.dir/event_loop.c.i

lib/CMakeFiles/Network_framework.dir/event_loop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/event_loop.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/event_loop.c -o CMakeFiles/Network_framework.dir/event_loop.c.s

lib/CMakeFiles/Network_framework.dir/event_loop_thread.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/event_loop_thread.c.o: ../lib/event_loop_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object lib/CMakeFiles/Network_framework.dir/event_loop_thread.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/event_loop_thread.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/event_loop_thread.c

lib/CMakeFiles/Network_framework.dir/event_loop_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/event_loop_thread.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/event_loop_thread.c > CMakeFiles/Network_framework.dir/event_loop_thread.c.i

lib/CMakeFiles/Network_framework.dir/event_loop_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/event_loop_thread.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/event_loop_thread.c -o CMakeFiles/Network_framework.dir/event_loop_thread.c.s

lib/CMakeFiles/Network_framework.dir/poll_dispatcher.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/poll_dispatcher.c.o: ../lib/poll_dispatcher.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object lib/CMakeFiles/Network_framework.dir/poll_dispatcher.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/poll_dispatcher.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/poll_dispatcher.c

lib/CMakeFiles/Network_framework.dir/poll_dispatcher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/poll_dispatcher.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/poll_dispatcher.c > CMakeFiles/Network_framework.dir/poll_dispatcher.c.i

lib/CMakeFiles/Network_framework.dir/poll_dispatcher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/poll_dispatcher.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/poll_dispatcher.c -o CMakeFiles/Network_framework.dir/poll_dispatcher.c.s

lib/CMakeFiles/Network_framework.dir/tcp_connection.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/tcp_connection.c.o: ../lib/tcp_connection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object lib/CMakeFiles/Network_framework.dir/tcp_connection.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/tcp_connection.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/tcp_connection.c

lib/CMakeFiles/Network_framework.dir/tcp_connection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/tcp_connection.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/tcp_connection.c > CMakeFiles/Network_framework.dir/tcp_connection.c.i

lib/CMakeFiles/Network_framework.dir/tcp_connection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/tcp_connection.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/tcp_connection.c -o CMakeFiles/Network_framework.dir/tcp_connection.c.s

lib/CMakeFiles/Network_framework.dir/tcp_server.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/tcp_server.c.o: ../lib/tcp_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object lib/CMakeFiles/Network_framework.dir/tcp_server.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/tcp_server.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/tcp_server.c

lib/CMakeFiles/Network_framework.dir/tcp_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/tcp_server.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/tcp_server.c > CMakeFiles/Network_framework.dir/tcp_server.c.i

lib/CMakeFiles/Network_framework.dir/tcp_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/tcp_server.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/tcp_server.c -o CMakeFiles/Network_framework.dir/tcp_server.c.s

lib/CMakeFiles/Network_framework.dir/thread_pool.c.o: lib/CMakeFiles/Network_framework.dir/flags.make
lib/CMakeFiles/Network_framework.dir/thread_pool.c.o: ../lib/thread_pool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object lib/CMakeFiles/Network_framework.dir/thread_pool.c.o"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Network_framework.dir/thread_pool.c.o   -c /Users/horson/Documents/V视频16/c++/socket_framework/lib/thread_pool.c

lib/CMakeFiles/Network_framework.dir/thread_pool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Network_framework.dir/thread_pool.c.i"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horson/Documents/V视频16/c++/socket_framework/lib/thread_pool.c > CMakeFiles/Network_framework.dir/thread_pool.c.i

lib/CMakeFiles/Network_framework.dir/thread_pool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Network_framework.dir/thread_pool.c.s"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horson/Documents/V视频16/c++/socket_framework/lib/thread_pool.c -o CMakeFiles/Network_framework.dir/thread_pool.c.s

# Object files for target Network_framework
Network_framework_OBJECTS = \
"CMakeFiles/Network_framework.dir/accepter.c.o" \
"CMakeFiles/Network_framework.dir/buffer.c.o" \
"CMakeFiles/Network_framework.dir/channel.c.o" \
"CMakeFiles/Network_framework.dir/channel_map.c.o" \
"CMakeFiles/Network_framework.dir/event_loop.c.o" \
"CMakeFiles/Network_framework.dir/event_loop_thread.c.o" \
"CMakeFiles/Network_framework.dir/poll_dispatcher.c.o" \
"CMakeFiles/Network_framework.dir/tcp_connection.c.o" \
"CMakeFiles/Network_framework.dir/tcp_server.c.o" \
"CMakeFiles/Network_framework.dir/thread_pool.c.o"

# External object files for target Network_framework
Network_framework_EXTERNAL_OBJECTS =

lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/accepter.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/buffer.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/channel.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/channel_map.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/event_loop.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/event_loop_thread.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/poll_dispatcher.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/tcp_connection.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/tcp_server.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/thread_pool.c.o
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/build.make
lib/libNetwork_framework.a: lib/CMakeFiles/Network_framework.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C static library libNetwork_framework.a"
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && $(CMAKE_COMMAND) -P CMakeFiles/Network_framework.dir/cmake_clean_target.cmake
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Network_framework.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/Network_framework.dir/build: lib/libNetwork_framework.a

.PHONY : lib/CMakeFiles/Network_framework.dir/build

lib/CMakeFiles/Network_framework.dir/clean:
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib && $(CMAKE_COMMAND) -P CMakeFiles/Network_framework.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/Network_framework.dir/clean

lib/CMakeFiles/Network_framework.dir/depend:
	cd /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/horson/Documents/V视频16/c++/socket_framework /Users/horson/Documents/V视频16/c++/socket_framework/lib /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib /Users/horson/Documents/V视频16/c++/socket_framework/cmake-build-debug/lib/CMakeFiles/Network_framework.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/Network_framework.dir/depend
