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
CMAKE_SOURCE_DIR = /Users/alex/ClionProjects/HelloWOrld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alex/ClionProjects/HelloWOrld/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HelloWOrld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloWOrld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloWOrld.dir/flags.make

CMakeFiles/HelloWOrld.dir/main.cpp.o: CMakeFiles/HelloWOrld.dir/flags.make
CMakeFiles/HelloWOrld.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alex/ClionProjects/HelloWOrld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloWOrld.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HelloWOrld.dir/main.cpp.o -c /Users/alex/ClionProjects/HelloWOrld/main.cpp

CMakeFiles/HelloWOrld.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWOrld.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alex/ClionProjects/HelloWOrld/main.cpp > CMakeFiles/HelloWOrld.dir/main.cpp.i

CMakeFiles/HelloWOrld.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWOrld.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alex/ClionProjects/HelloWOrld/main.cpp -o CMakeFiles/HelloWOrld.dir/main.cpp.s

CMakeFiles/HelloWOrld.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/HelloWOrld.dir/main.cpp.o.requires

CMakeFiles/HelloWOrld.dir/main.cpp.o.provides: CMakeFiles/HelloWOrld.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/HelloWOrld.dir/build.make CMakeFiles/HelloWOrld.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/HelloWOrld.dir/main.cpp.o.provides

CMakeFiles/HelloWOrld.dir/main.cpp.o.provides.build: CMakeFiles/HelloWOrld.dir/main.cpp.o


# Object files for target HelloWOrld
HelloWOrld_OBJECTS = \
"CMakeFiles/HelloWOrld.dir/main.cpp.o"

# External object files for target HelloWOrld
HelloWOrld_EXTERNAL_OBJECTS =

HelloWOrld: CMakeFiles/HelloWOrld.dir/main.cpp.o
HelloWOrld: CMakeFiles/HelloWOrld.dir/build.make
HelloWOrld: CMakeFiles/HelloWOrld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alex/ClionProjects/HelloWOrld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloWOrld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HelloWOrld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloWOrld.dir/build: HelloWOrld

.PHONY : CMakeFiles/HelloWOrld.dir/build

CMakeFiles/HelloWOrld.dir/requires: CMakeFiles/HelloWOrld.dir/main.cpp.o.requires

.PHONY : CMakeFiles/HelloWOrld.dir/requires

CMakeFiles/HelloWOrld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HelloWOrld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HelloWOrld.dir/clean

CMakeFiles/HelloWOrld.dir/depend:
	cd /Users/alex/ClionProjects/HelloWOrld/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alex/ClionProjects/HelloWOrld /Users/alex/ClionProjects/HelloWOrld /Users/alex/ClionProjects/HelloWOrld/cmake-build-debug /Users/alex/ClionProjects/HelloWOrld/cmake-build-debug /Users/alex/ClionProjects/HelloWOrld/cmake-build-debug/CMakeFiles/HelloWOrld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloWOrld.dir/depend

