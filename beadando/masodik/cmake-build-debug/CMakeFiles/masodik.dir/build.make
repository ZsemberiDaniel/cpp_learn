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
CMAKE_SOURCE_DIR = C:\cpp\cpp_learn\beadando\masodik

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\cpp\cpp_learn\beadando\masodik\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/masodik.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/masodik.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/masodik.dir/flags.make

CMakeFiles/masodik.dir/main.cpp.obj: CMakeFiles/masodik.dir/flags.make
CMakeFiles/masodik.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\cpp\cpp_learn\beadando\masodik\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/masodik.dir/main.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\masodik.dir\main.cpp.obj -c C:\cpp\cpp_learn\beadando\masodik\main.cpp

CMakeFiles/masodik.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/masodik.dir/main.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\cpp\cpp_learn\beadando\masodik\main.cpp > CMakeFiles\masodik.dir\main.cpp.i

CMakeFiles/masodik.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/masodik.dir/main.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\cpp\cpp_learn\beadando\masodik\main.cpp -o CMakeFiles\masodik.dir\main.cpp.s

# Object files for target masodik
masodik_OBJECTS = \
"CMakeFiles/masodik.dir/main.cpp.obj"

# External object files for target masodik
masodik_EXTERNAL_OBJECTS =

masodik.exe: CMakeFiles/masodik.dir/main.cpp.obj
masodik.exe: CMakeFiles/masodik.dir/build.make
masodik.exe: CMakeFiles/masodik.dir/linklibs.rsp
masodik.exe: CMakeFiles/masodik.dir/objects1.rsp
masodik.exe: CMakeFiles/masodik.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\cpp\cpp_learn\beadando\masodik\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable masodik.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\masodik.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/masodik.dir/build: masodik.exe

.PHONY : CMakeFiles/masodik.dir/build

CMakeFiles/masodik.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\masodik.dir\cmake_clean.cmake
.PHONY : CMakeFiles/masodik.dir/clean

CMakeFiles/masodik.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\cpp\cpp_learn\beadando\masodik C:\cpp\cpp_learn\beadando\masodik C:\cpp\cpp_learn\beadando\masodik\cmake-build-debug C:\cpp\cpp_learn\beadando\masodik\cmake-build-debug C:\cpp\cpp_learn\beadando\masodik\cmake-build-debug\CMakeFiles\masodik.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/masodik.dir/depend

