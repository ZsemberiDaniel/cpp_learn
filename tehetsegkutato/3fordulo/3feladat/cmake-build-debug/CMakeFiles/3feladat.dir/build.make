# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/zsdaniel/Code/ides/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zsdaniel/Code/ides/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3feladat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3feladat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3feladat.dir/flags.make

CMakeFiles/3feladat.dir/main.cpp.o: CMakeFiles/3feladat.dir/flags.make
CMakeFiles/3feladat.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3feladat.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3feladat.dir/main.cpp.o -c /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/main.cpp

CMakeFiles/3feladat.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3feladat.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/main.cpp > CMakeFiles/3feladat.dir/main.cpp.i

CMakeFiles/3feladat.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3feladat.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/main.cpp -o CMakeFiles/3feladat.dir/main.cpp.s

# Object files for target 3feladat
3feladat_OBJECTS = \
"CMakeFiles/3feladat.dir/main.cpp.o"

# External object files for target 3feladat
3feladat_EXTERNAL_OBJECTS =

3feladat: CMakeFiles/3feladat.dir/main.cpp.o
3feladat: CMakeFiles/3feladat.dir/build.make
3feladat: CMakeFiles/3feladat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3feladat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3feladat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3feladat.dir/build: 3feladat

.PHONY : CMakeFiles/3feladat.dir/build

CMakeFiles/3feladat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3feladat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3feladat.dir/clean

CMakeFiles/3feladat.dir/depend:
	cd /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/cmake-build-debug /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/cmake-build-debug /home/zsdaniel/Code/source/tehetsegkutato/3fordulo/3feladat/cmake-build-debug/CMakeFiles/3feladat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3feladat.dir/depend

