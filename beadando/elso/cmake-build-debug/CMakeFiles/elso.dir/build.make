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
CMAKE_SOURCE_DIR = C:\cpp\cpp_learn\beadando\elso

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\cpp\cpp_learn\beadando\elso\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/elso.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/elso.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/elso.dir/flags.make

CMakeFiles/elso.dir/main.cpp.obj: CMakeFiles/elso.dir/flags.make
CMakeFiles/elso.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\cpp\cpp_learn\beadando\elso\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/elso.dir/main.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\elso.dir\main.cpp.obj -c C:\cpp\cpp_learn\beadando\elso\main.cpp

CMakeFiles/elso.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/elso.dir/main.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\cpp\cpp_learn\beadando\elso\main.cpp > CMakeFiles\elso.dir\main.cpp.i

CMakeFiles/elso.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/elso.dir/main.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\cpp\cpp_learn\beadando\elso\main.cpp -o CMakeFiles\elso.dir\main.cpp.s

# Object files for target elso
elso_OBJECTS = \
"CMakeFiles/elso.dir/main.cpp.obj"

# External object files for target elso
elso_EXTERNAL_OBJECTS =

elso.exe: CMakeFiles/elso.dir/main.cpp.obj
elso.exe: CMakeFiles/elso.dir/build.make
elso.exe: CMakeFiles/elso.dir/linklibs.rsp
elso.exe: CMakeFiles/elso.dir/objects1.rsp
elso.exe: CMakeFiles/elso.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\cpp\cpp_learn\beadando\elso\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable elso.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\elso.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/elso.dir/build: elso.exe

.PHONY : CMakeFiles/elso.dir/build

CMakeFiles/elso.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\elso.dir\cmake_clean.cmake
.PHONY : CMakeFiles/elso.dir/clean

CMakeFiles/elso.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\cpp\cpp_learn\beadando\elso C:\cpp\cpp_learn\beadando\elso C:\cpp\cpp_learn\beadando\elso\cmake-build-debug C:\cpp\cpp_learn\beadando\elso\cmake-build-debug C:\cpp\cpp_learn\beadando\elso\cmake-build-debug\CMakeFiles\elso.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/elso.dir/depend

