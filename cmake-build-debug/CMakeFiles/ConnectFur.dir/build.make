# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Alex/CLionProjects/ConnectFur

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Alex/CLionProjects/ConnectFur/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ConnectFur.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ConnectFur.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ConnectFur.dir/flags.make

CMakeFiles/ConnectFur.dir/main.cpp.o: CMakeFiles/ConnectFur.dir/flags.make
CMakeFiles/ConnectFur.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Alex/CLionProjects/ConnectFur/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ConnectFur.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ConnectFur.dir/main.cpp.o -c /Users/Alex/CLionProjects/ConnectFur/main.cpp

CMakeFiles/ConnectFur.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ConnectFur.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Alex/CLionProjects/ConnectFur/main.cpp > CMakeFiles/ConnectFur.dir/main.cpp.i

CMakeFiles/ConnectFur.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ConnectFur.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Alex/CLionProjects/ConnectFur/main.cpp -o CMakeFiles/ConnectFur.dir/main.cpp.s

CMakeFiles/ConnectFur.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ConnectFur.dir/main.cpp.o.requires

CMakeFiles/ConnectFur.dir/main.cpp.o.provides: CMakeFiles/ConnectFur.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ConnectFur.dir/build.make CMakeFiles/ConnectFur.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ConnectFur.dir/main.cpp.o.provides

CMakeFiles/ConnectFur.dir/main.cpp.o.provides.build: CMakeFiles/ConnectFur.dir/main.cpp.o


# Object files for target ConnectFur
ConnectFur_OBJECTS = \
"CMakeFiles/ConnectFur.dir/main.cpp.o"

# External object files for target ConnectFur
ConnectFur_EXTERNAL_OBJECTS =

ConnectFur: CMakeFiles/ConnectFur.dir/main.cpp.o
ConnectFur: CMakeFiles/ConnectFur.dir/build.make
ConnectFur: CMakeFiles/ConnectFur.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Alex/CLionProjects/ConnectFur/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ConnectFur"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ConnectFur.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ConnectFur.dir/build: ConnectFur

.PHONY : CMakeFiles/ConnectFur.dir/build

CMakeFiles/ConnectFur.dir/requires: CMakeFiles/ConnectFur.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ConnectFur.dir/requires

CMakeFiles/ConnectFur.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ConnectFur.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ConnectFur.dir/clean

CMakeFiles/ConnectFur.dir/depend:
	cd /Users/Alex/CLionProjects/ConnectFur/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Alex/CLionProjects/ConnectFur /Users/Alex/CLionProjects/ConnectFur /Users/Alex/CLionProjects/ConnectFur/cmake-build-debug /Users/Alex/CLionProjects/ConnectFur/cmake-build-debug /Users/Alex/CLionProjects/ConnectFur/cmake-build-debug/CMakeFiles/ConnectFur.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ConnectFur.dir/depend

