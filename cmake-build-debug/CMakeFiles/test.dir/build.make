# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\joyce\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\joyce\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test/main.cpp.obj: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test/main.cpp.obj: C:/Users/joyce/Documents/Code/C++/InClassBrian/PROG2400-700-Lectures/test/main.cpp
CMakeFiles/test.dir/test/main.cpp.obj: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/test/main.cpp.obj"
	C:\Users\joyce\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/test/main.cpp.obj -MF CMakeFiles\test.dir\test\main.cpp.obj.d -o CMakeFiles\test.dir\test\main.cpp.obj -c C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\test\main.cpp

CMakeFiles/test.dir/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test/main.cpp.i"
	C:\Users\joyce\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\test\main.cpp > CMakeFiles\test.dir\test\main.cpp.i

CMakeFiles/test.dir/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test/main.cpp.s"
	C:\Users\joyce\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\test\main.cpp -o CMakeFiles\test.dir\test\main.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test/main.cpp.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

test.exe: CMakeFiles/test.dir/test/main.cpp.obj
test.exe: CMakeFiles/test.dir/build.make
test.exe: CMakeFiles/test.dir/linklibs.rsp
test.exe: CMakeFiles/test.dir/objects1.rsp
test.exe: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test.exe
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\cmake-build-debug C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\cmake-build-debug C:\Users\joyce\Documents\Code\C++\InClassBrian\PROG2400-700-Lectures\cmake-build-debug\CMakeFiles\test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend
