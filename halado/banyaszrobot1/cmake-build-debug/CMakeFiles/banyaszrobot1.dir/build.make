# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\cpp\cpp_learn\halado\banyaszrobot1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\cpp\cpp_learn\halado\banyaszrobot1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/banyaszrobot1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/banyaszrobot1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/banyaszrobot1.dir/flags.make

CMakeFiles/banyaszrobot1.dir/main.cpp.obj: CMakeFiles/banyaszrobot1.dir/flags.make
CMakeFiles/banyaszrobot1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\cpp\cpp_learn\halado\banyaszrobot1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/banyaszrobot1.dir/main.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\banyaszrobot1.dir\main.cpp.obj -c C:\cpp\cpp_learn\halado\banyaszrobot1\main.cpp

CMakeFiles/banyaszrobot1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/banyaszrobot1.dir/main.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\cpp\cpp_learn\halado\banyaszrobot1\main.cpp > CMakeFiles\banyaszrobot1.dir\main.cpp.i

CMakeFiles/banyaszrobot1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/banyaszrobot1.dir/main.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\cpp\cpp_learn\halado\banyaszrobot1\main.cpp -o CMakeFiles\banyaszrobot1.dir\main.cpp.s

# Object files for target banyaszrobot1
banyaszrobot1_OBJECTS = \
"CMakeFiles/banyaszrobot1.dir/main.cpp.obj"

# External object files for target banyaszrobot1
banyaszrobot1_EXTERNAL_OBJECTS =

banyaszrobot1.exe: CMakeFiles/banyaszrobot1.dir/main.cpp.obj
banyaszrobot1.exe: CMakeFiles/banyaszrobot1.dir/build.make
banyaszrobot1.exe: CMakeFiles/banyaszrobot1.dir/linklibs.rsp
banyaszrobot1.exe: CMakeFiles/banyaszrobot1.dir/objects1.rsp
banyaszrobot1.exe: CMakeFiles/banyaszrobot1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\cpp\cpp_learn\halado\banyaszrobot1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable banyaszrobot1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\banyaszrobot1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/banyaszrobot1.dir/build: banyaszrobot1.exe

.PHONY : CMakeFiles/banyaszrobot1.dir/build

CMakeFiles/banyaszrobot1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\banyaszrobot1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/banyaszrobot1.dir/clean

CMakeFiles/banyaszrobot1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\cpp\cpp_learn\halado\banyaszrobot1 C:\cpp\cpp_learn\halado\banyaszrobot1 C:\cpp\cpp_learn\halado\banyaszrobot1\cmake-build-debug C:\cpp\cpp_learn\halado\banyaszrobot1\cmake-build-debug C:\cpp\cpp_learn\halado\banyaszrobot1\cmake-build-debug\CMakeFiles\banyaszrobot1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/banyaszrobot1.dir/depend

