# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task_01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task_01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task_01.dir/flags.make

CMakeFiles/task_01.dir/main.cpp.o: CMakeFiles/task_01.dir/flags.make
CMakeFiles/task_01.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task_01.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task_01.dir/main.cpp.o -c /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/main.cpp

CMakeFiles/task_01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_01.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/main.cpp > CMakeFiles/task_01.dir/main.cpp.i

CMakeFiles/task_01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_01.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/main.cpp -o CMakeFiles/task_01.dir/main.cpp.s

CMakeFiles/task_01.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/task_01.dir/main.cpp.o.requires

CMakeFiles/task_01.dir/main.cpp.o.provides: CMakeFiles/task_01.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/task_01.dir/build.make CMakeFiles/task_01.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/task_01.dir/main.cpp.o.provides

CMakeFiles/task_01.dir/main.cpp.o.provides.build: CMakeFiles/task_01.dir/main.cpp.o


# Object files for target task_01
task_01_OBJECTS = \
"CMakeFiles/task_01.dir/main.cpp.o"

# External object files for target task_01
task_01_EXTERNAL_OBJECTS =

task_01: CMakeFiles/task_01.dir/main.cpp.o
task_01: CMakeFiles/task_01.dir/build.make
task_01: CMakeFiles/task_01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task_01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task_01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task_01.dir/build: task_01

.PHONY : CMakeFiles/task_01.dir/build

CMakeFiles/task_01.dir/requires: CMakeFiles/task_01.dir/main.cpp.o.requires

.PHONY : CMakeFiles/task_01.dir/requires

CMakeFiles/task_01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task_01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task_01.dir/clean

CMakeFiles/task_01.dir/depend:
	cd /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01 /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01 /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/cmake-build-debug /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/cmake-build-debug /Users/andrey/TECHNOPARK_SYSARC/SEM_01/Algol/hw/modul_01/task_01/cmake-build-debug/CMakeFiles/task_01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task_01.dir/depend

