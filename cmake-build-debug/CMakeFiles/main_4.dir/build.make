# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/admin/studbaza/sem_5/wzaip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/admin/studbaza/sem_5/wzaip/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_4.dir/flags.make

CMakeFiles/main_4.dir/Krzyzak.cpp.o: CMakeFiles/main_4.dir/flags.make
CMakeFiles/main_4.dir/Krzyzak.cpp.o: ../Krzyzak.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/admin/studbaza/sem_5/wzaip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_4.dir/Krzyzak.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_4.dir/Krzyzak.cpp.o -c /home/admin/studbaza/sem_5/wzaip/Krzyzak.cpp

CMakeFiles/main_4.dir/Krzyzak.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_4.dir/Krzyzak.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/admin/studbaza/sem_5/wzaip/Krzyzak.cpp > CMakeFiles/main_4.dir/Krzyzak.cpp.i

CMakeFiles/main_4.dir/Krzyzak.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_4.dir/Krzyzak.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/admin/studbaza/sem_5/wzaip/Krzyzak.cpp -o CMakeFiles/main_4.dir/Krzyzak.cpp.s

CMakeFiles/main_4.dir/Krzyzak.cpp.o.requires:

.PHONY : CMakeFiles/main_4.dir/Krzyzak.cpp.o.requires

CMakeFiles/main_4.dir/Krzyzak.cpp.o.provides: CMakeFiles/main_4.dir/Krzyzak.cpp.o.requires
	$(MAKE) -f CMakeFiles/main_4.dir/build.make CMakeFiles/main_4.dir/Krzyzak.cpp.o.provides.build
.PHONY : CMakeFiles/main_4.dir/Krzyzak.cpp.o.provides

CMakeFiles/main_4.dir/Krzyzak.cpp.o.provides.build: CMakeFiles/main_4.dir/Krzyzak.cpp.o


# Object files for target main_4
main_4_OBJECTS = \
"CMakeFiles/main_4.dir/Krzyzak.cpp.o"

# External object files for target main_4
main_4_EXTERNAL_OBJECTS =

main_4: CMakeFiles/main_4.dir/Krzyzak.cpp.o
main_4: CMakeFiles/main_4.dir/build.make
main_4: CMakeFiles/main_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/admin/studbaza/sem_5/wzaip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_4.dir/build: main_4

.PHONY : CMakeFiles/main_4.dir/build

CMakeFiles/main_4.dir/requires: CMakeFiles/main_4.dir/Krzyzak.cpp.o.requires

.PHONY : CMakeFiles/main_4.dir/requires

CMakeFiles/main_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_4.dir/clean

CMakeFiles/main_4.dir/depend:
	cd /home/admin/studbaza/sem_5/wzaip/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/admin/studbaza/sem_5/wzaip /home/admin/studbaza/sem_5/wzaip /home/admin/studbaza/sem_5/wzaip/cmake-build-debug /home/admin/studbaza/sem_5/wzaip/cmake-build-debug /home/admin/studbaza/sem_5/wzaip/cmake-build-debug/CMakeFiles/main_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_4.dir/depend

