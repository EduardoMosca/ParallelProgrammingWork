# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eduardo/Desktop/programas/c/ParallelProgrammingWork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/build

# Include any dependencies generated for this target.
include CMakeFiles/trabalhoPPC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/trabalhoPPC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/trabalhoPPC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trabalhoPPC.dir/flags.make

CMakeFiles/trabalhoPPC.dir/main.c.o: CMakeFiles/trabalhoPPC.dir/flags.make
CMakeFiles/trabalhoPPC.dir/main.c.o: /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/main.c
CMakeFiles/trabalhoPPC.dir/main.c.o: CMakeFiles/trabalhoPPC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/programas/c/ParallelProgrammingWork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/trabalhoPPC.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/trabalhoPPC.dir/main.c.o -MF CMakeFiles/trabalhoPPC.dir/main.c.o.d -o CMakeFiles/trabalhoPPC.dir/main.c.o -c /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/main.c

CMakeFiles/trabalhoPPC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalhoPPC.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/main.c > CMakeFiles/trabalhoPPC.dir/main.c.i

CMakeFiles/trabalhoPPC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalhoPPC.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/main.c -o CMakeFiles/trabalhoPPC.dir/main.c.s

# Object files for target trabalhoPPC
trabalhoPPC_OBJECTS = \
"CMakeFiles/trabalhoPPC.dir/main.c.o"

# External object files for target trabalhoPPC
trabalhoPPC_EXTERNAL_OBJECTS =

trabalhoPPC: CMakeFiles/trabalhoPPC.dir/main.c.o
trabalhoPPC: CMakeFiles/trabalhoPPC.dir/build.make
trabalhoPPC: /usr/lib/libSDL2main.a
trabalhoPPC: /usr/lib/libSDL2-2.0.so.0.2600.1
trabalhoPPC: /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/src/queue.c
trabalhoPPC: CMakeFiles/trabalhoPPC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eduardo/Desktop/programas/c/ParallelProgrammingWork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable trabalhoPPC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trabalhoPPC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trabalhoPPC.dir/build: trabalhoPPC
.PHONY : CMakeFiles/trabalhoPPC.dir/build

CMakeFiles/trabalhoPPC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trabalhoPPC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trabalhoPPC.dir/clean

CMakeFiles/trabalhoPPC.dir/depend:
	cd /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eduardo/Desktop/programas/c/ParallelProgrammingWork /home/eduardo/Desktop/programas/c/ParallelProgrammingWork /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/build /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/build /home/eduardo/Desktop/programas/c/ParallelProgrammingWork/build/CMakeFiles/trabalhoPPC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trabalhoPPC.dir/depend

