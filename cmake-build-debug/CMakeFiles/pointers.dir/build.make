# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\Users\W0471965\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\W0471965\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\W0471965\CLionProjects\InClassFollowUp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\W0471965\CLionProjects\InClassFollowUp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pointers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pointers.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pointers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pointers.dir/flags.make

CMakeFiles/pointers.dir/pointers/main.cpp.obj: CMakeFiles/pointers.dir/flags.make
CMakeFiles/pointers.dir/pointers/main.cpp.obj: C:/Users/W0471965/CLionProjects/InClassFollowUp/pointers/main.cpp
CMakeFiles/pointers.dir/pointers/main.cpp.obj: CMakeFiles/pointers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\W0471965\CLionProjects\InClassFollowUp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pointers.dir/pointers/main.cpp.obj"
	C:\Users\W0471965\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pointers.dir/pointers/main.cpp.obj -MF CMakeFiles\pointers.dir\pointers\main.cpp.obj.d -o CMakeFiles\pointers.dir\pointers\main.cpp.obj -c C:\Users\W0471965\CLionProjects\InClassFollowUp\pointers\main.cpp

CMakeFiles/pointers.dir/pointers/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pointers.dir/pointers/main.cpp.i"
	C:\Users\W0471965\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\W0471965\CLionProjects\InClassFollowUp\pointers\main.cpp > CMakeFiles\pointers.dir\pointers\main.cpp.i

CMakeFiles/pointers.dir/pointers/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pointers.dir/pointers/main.cpp.s"
	C:\Users\W0471965\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\W0471965\CLionProjects\InClassFollowUp\pointers\main.cpp -o CMakeFiles\pointers.dir\pointers\main.cpp.s

# Object files for target pointers
pointers_OBJECTS = \
"CMakeFiles/pointers.dir/pointers/main.cpp.obj"

# External object files for target pointers
pointers_EXTERNAL_OBJECTS =

pointers.exe: CMakeFiles/pointers.dir/pointers/main.cpp.obj
pointers.exe: CMakeFiles/pointers.dir/build.make
pointers.exe: CMakeFiles/pointers.dir/linkLibs.rsp
pointers.exe: CMakeFiles/pointers.dir/objects1.rsp
pointers.exe: CMakeFiles/pointers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\W0471965\CLionProjects\InClassFollowUp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pointers.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pointers.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pointers.dir/build: pointers.exe
.PHONY : CMakeFiles/pointers.dir/build

CMakeFiles/pointers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pointers.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pointers.dir/clean

CMakeFiles/pointers.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\W0471965\CLionProjects\InClassFollowUp C:\Users\W0471965\CLionProjects\InClassFollowUp C:\Users\W0471965\CLionProjects\InClassFollowUp\cmake-build-debug C:\Users\W0471965\CLionProjects\InClassFollowUp\cmake-build-debug C:\Users\W0471965\CLionProjects\InClassFollowUp\cmake-build-debug\CMakeFiles\pointers.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pointers.dir/depend
