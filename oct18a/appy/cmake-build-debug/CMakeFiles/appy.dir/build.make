# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /home/zsdaniel/Code/source/cpp_learn/oct18a/appy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zsdaniel/Code/source/cpp_learn/oct18a/appy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/appy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/appy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/appy.dir/flags.make

CMakeFiles/appy.dir/main.cpp.o: CMakeFiles/appy.dir/flags.make
CMakeFiles/appy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zsdaniel/Code/source/cpp_learn/oct18a/appy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/appy.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/appy.dir/main.cpp.o -c /home/zsdaniel/Code/source/cpp_learn/oct18a/appy/main.cpp

CMakeFiles/appy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/appy.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zsdaniel/Code/source/cpp_learn/oct18a/appy/main.cpp > CMakeFiles/appy.dir/main.cpp.i

CMakeFiles/appy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/appy.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zsdaniel/Code/source/cpp_learn/oct18a/appy/main.cpp -o CMakeFiles/appy.dir/main.cpp.s

# Object files for target appy
appy_OBJECTS = \
"CMakeFiles/appy.dir/main.cpp.o"

# External object files for target appy
appy_EXTERNAL_OBJECTS =

appy: CMakeFiles/appy.dir/main.cpp.o
appy: CMakeFiles/appy.dir/build.make
appy: CMakeFiles/appy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zsdaniel/Code/source/cpp_learn/oct18a/appy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable appy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/appy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/appy.dir/build: appy

.PHONY : CMakeFiles/appy.dir/build

CMakeFiles/appy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/appy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/appy.dir/clean

CMakeFiles/appy.dir/depend:
	cd /home/zsdaniel/Code/source/cpp_learn/oct18a/appy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zsdaniel/Code/source/cpp_learn/oct18a/appy /home/zsdaniel/Code/source/cpp_learn/oct18a/appy /home/zsdaniel/Code/source/cpp_learn/oct18a/appy/cmake-build-debug /home/zsdaniel/Code/source/cpp_learn/oct18a/appy/cmake-build-debug /home/zsdaniel/Code/source/cpp_learn/oct18a/appy/cmake-build-debug/CMakeFiles/appy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/appy.dir/depend

