# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "/Applications/CLion 2.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Applications/CLion 2.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alex/ClionProjects/Deadline

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alex/ClionProjects/Deadline/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Deadline.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Deadline.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Deadline.dir/flags.make

CMakeFiles/Deadline.dir/main.cpp.o: CMakeFiles/Deadline.dir/flags.make
CMakeFiles/Deadline.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alex/ClionProjects/Deadline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Deadline.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Deadline.dir/main.cpp.o -c /Users/alex/ClionProjects/Deadline/main.cpp

CMakeFiles/Deadline.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Deadline.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alex/ClionProjects/Deadline/main.cpp > CMakeFiles/Deadline.dir/main.cpp.i

CMakeFiles/Deadline.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Deadline.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alex/ClionProjects/Deadline/main.cpp -o CMakeFiles/Deadline.dir/main.cpp.s

CMakeFiles/Deadline.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Deadline.dir/main.cpp.o.requires

CMakeFiles/Deadline.dir/main.cpp.o.provides: CMakeFiles/Deadline.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Deadline.dir/build.make CMakeFiles/Deadline.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Deadline.dir/main.cpp.o.provides

CMakeFiles/Deadline.dir/main.cpp.o.provides.build: CMakeFiles/Deadline.dir/main.cpp.o


# Object files for target Deadline
Deadline_OBJECTS = \
"CMakeFiles/Deadline.dir/main.cpp.o"

# External object files for target Deadline
Deadline_EXTERNAL_OBJECTS =

Deadline: CMakeFiles/Deadline.dir/main.cpp.o
Deadline: CMakeFiles/Deadline.dir/build.make
Deadline: CMakeFiles/Deadline.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alex/ClionProjects/Deadline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Deadline"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Deadline.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Deadline.dir/build: Deadline

.PHONY : CMakeFiles/Deadline.dir/build

CMakeFiles/Deadline.dir/requires: CMakeFiles/Deadline.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Deadline.dir/requires

CMakeFiles/Deadline.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Deadline.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Deadline.dir/clean

CMakeFiles/Deadline.dir/depend:
	cd /Users/alex/ClionProjects/Deadline/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alex/ClionProjects/Deadline /Users/alex/ClionProjects/Deadline /Users/alex/ClionProjects/Deadline/cmake-build-debug /Users/alex/ClionProjects/Deadline/cmake-build-debug /Users/alex/ClionProjects/Deadline/cmake-build-debug/CMakeFiles/Deadline.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Deadline.dir/depend

