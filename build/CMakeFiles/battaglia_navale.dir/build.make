# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luca-pi/Desktop/labProg/provaFinale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luca-pi/Desktop/labProg/provaFinale/build

# Include any dependencies generated for this target.
include CMakeFiles/battaglia_navale.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/battaglia_navale.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/battaglia_navale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/battaglia_navale.dir/flags.make

CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o: CMakeFiles/battaglia_navale.dir/flags.make
CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o: /home/luca-pi/Desktop/labProg/provaFinale/src/battaglia_navale.cpp
CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o: CMakeFiles/battaglia_navale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luca-pi/Desktop/labProg/provaFinale/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o -MF CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o.d -o CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o -c /home/luca-pi/Desktop/labProg/provaFinale/src/battaglia_navale.cpp

CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luca-pi/Desktop/labProg/provaFinale/src/battaglia_navale.cpp > CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.i

CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luca-pi/Desktop/labProg/provaFinale/src/battaglia_navale.cpp -o CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.s

# Object files for target battaglia_navale
battaglia_navale_OBJECTS = \
"CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o"

# External object files for target battaglia_navale
battaglia_navale_EXTERNAL_OBJECTS =

battaglia_navale: CMakeFiles/battaglia_navale.dir/src/battaglia_navale.cpp.o
battaglia_navale: CMakeFiles/battaglia_navale.dir/build.make
battaglia_navale: libProFinale.a
battaglia_navale: CMakeFiles/battaglia_navale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luca-pi/Desktop/labProg/provaFinale/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable battaglia_navale"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/battaglia_navale.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/battaglia_navale.dir/build: battaglia_navale
.PHONY : CMakeFiles/battaglia_navale.dir/build

CMakeFiles/battaglia_navale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/battaglia_navale.dir/cmake_clean.cmake
.PHONY : CMakeFiles/battaglia_navale.dir/clean

CMakeFiles/battaglia_navale.dir/depend:
	cd /home/luca-pi/Desktop/labProg/provaFinale/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luca-pi/Desktop/labProg/provaFinale /home/luca-pi/Desktop/labProg/provaFinale /home/luca-pi/Desktop/labProg/provaFinale/build /home/luca-pi/Desktop/labProg/provaFinale/build /home/luca-pi/Desktop/labProg/provaFinale/build/CMakeFiles/battaglia_navale.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/battaglia_navale.dir/depend

