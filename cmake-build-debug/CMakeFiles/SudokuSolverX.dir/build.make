# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /cygdrive/c/Users/hugod/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/hugod/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SudokuSolverX.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SudokuSolverX.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SudokuSolverX.dir/flags.make

CMakeFiles/SudokuSolverX.dir/main.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SudokuSolverX.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/main.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/main.c

CMakeFiles/SudokuSolverX.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/main.c > CMakeFiles/SudokuSolverX.dir/main.c.i

CMakeFiles/SudokuSolverX.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/main.c -o CMakeFiles/SudokuSolverX.dir/main.c.s

CMakeFiles/SudokuSolverX.dir/Helpers.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/Helpers.c.o: ../Helpers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SudokuSolverX.dir/Helpers.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/Helpers.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/Helpers.c

CMakeFiles/SudokuSolverX.dir/Helpers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/Helpers.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/Helpers.c > CMakeFiles/SudokuSolverX.dir/Helpers.c.i

CMakeFiles/SudokuSolverX.dir/Helpers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/Helpers.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/Helpers.c -o CMakeFiles/SudokuSolverX.dir/Helpers.c.s

CMakeFiles/SudokuSolverX.dir/Consistency.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/Consistency.c.o: ../Consistency.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SudokuSolverX.dir/Consistency.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/Consistency.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/Consistency.c

CMakeFiles/SudokuSolverX.dir/Consistency.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/Consistency.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/Consistency.c > CMakeFiles/SudokuSolverX.dir/Consistency.c.i

CMakeFiles/SudokuSolverX.dir/Consistency.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/Consistency.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/Consistency.c -o CMakeFiles/SudokuSolverX.dir/Consistency.c.s

CMakeFiles/SudokuSolverX.dir/tests.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/tests.c.o: ../tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SudokuSolverX.dir/tests.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/tests.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/tests.c

CMakeFiles/SudokuSolverX.dir/tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/tests.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/tests.c > CMakeFiles/SudokuSolverX.dir/tests.c.i

CMakeFiles/SudokuSolverX.dir/tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/tests.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/tests.c -o CMakeFiles/SudokuSolverX.dir/tests.c.s

CMakeFiles/SudokuSolverX.dir/BruteForce.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/BruteForce.c.o: ../BruteForce.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/SudokuSolverX.dir/BruteForce.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/BruteForce.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/BruteForce.c

CMakeFiles/SudokuSolverX.dir/BruteForce.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/BruteForce.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/BruteForce.c > CMakeFiles/SudokuSolverX.dir/BruteForce.c.i

CMakeFiles/SudokuSolverX.dir/BruteForce.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/BruteForce.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/BruteForce.c -o CMakeFiles/SudokuSolverX.dir/BruteForce.c.s

CMakeFiles/SudokuSolverX.dir/FileManip.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/FileManip.c.o: ../FileManip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/SudokuSolverX.dir/FileManip.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/FileManip.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/FileManip.c

CMakeFiles/SudokuSolverX.dir/FileManip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/FileManip.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/FileManip.c > CMakeFiles/SudokuSolverX.dir/FileManip.c.i

CMakeFiles/SudokuSolverX.dir/FileManip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/FileManip.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/FileManip.c -o CMakeFiles/SudokuSolverX.dir/FileManip.c.s

CMakeFiles/SudokuSolverX.dir/strategies.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/strategies.c.o: ../strategies.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/SudokuSolverX.dir/strategies.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/strategies.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/strategies.c

CMakeFiles/SudokuSolverX.dir/strategies.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/strategies.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/strategies.c > CMakeFiles/SudokuSolverX.dir/strategies.c.i

CMakeFiles/SudokuSolverX.dir/strategies.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/strategies.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/strategies.c -o CMakeFiles/SudokuSolverX.dir/strategies.c.s

CMakeFiles/SudokuSolverX.dir/hidden_singles.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/hidden_singles.c.o: ../hidden_singles.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/SudokuSolverX.dir/hidden_singles.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/hidden_singles.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/hidden_singles.c

CMakeFiles/SudokuSolverX.dir/hidden_singles.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/hidden_singles.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/hidden_singles.c > CMakeFiles/SudokuSolverX.dir/hidden_singles.c.i

CMakeFiles/SudokuSolverX.dir/hidden_singles.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/hidden_singles.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/hidden_singles.c -o CMakeFiles/SudokuSolverX.dir/hidden_singles.c.s

CMakeFiles/SudokuSolverX.dir/naked_pairs.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/naked_pairs.c.o: ../naked_pairs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/SudokuSolverX.dir/naked_pairs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/naked_pairs.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/naked_pairs.c

CMakeFiles/SudokuSolverX.dir/naked_pairs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/naked_pairs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/naked_pairs.c > CMakeFiles/SudokuSolverX.dir/naked_pairs.c.i

CMakeFiles/SudokuSolverX.dir/naked_pairs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/naked_pairs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/naked_pairs.c -o CMakeFiles/SudokuSolverX.dir/naked_pairs.c.s

CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.o: ../pointing_pairs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/pointing_pairs.c

CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/pointing_pairs.c > CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.i

CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/pointing_pairs.c -o CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.s

CMakeFiles/SudokuSolverX.dir/box_reduction.c.o: CMakeFiles/SudokuSolverX.dir/flags.make
CMakeFiles/SudokuSolverX.dir/box_reduction.c.o: ../box_reduction.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/SudokuSolverX.dir/box_reduction.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolverX.dir/box_reduction.c.o   -c /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/box_reduction.c

CMakeFiles/SudokuSolverX.dir/box_reduction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolverX.dir/box_reduction.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/box_reduction.c > CMakeFiles/SudokuSolverX.dir/box_reduction.c.i

CMakeFiles/SudokuSolverX.dir/box_reduction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolverX.dir/box_reduction.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/box_reduction.c -o CMakeFiles/SudokuSolverX.dir/box_reduction.c.s

# Object files for target SudokuSolverX
SudokuSolverX_OBJECTS = \
"CMakeFiles/SudokuSolverX.dir/main.c.o" \
"CMakeFiles/SudokuSolverX.dir/Helpers.c.o" \
"CMakeFiles/SudokuSolverX.dir/Consistency.c.o" \
"CMakeFiles/SudokuSolverX.dir/tests.c.o" \
"CMakeFiles/SudokuSolverX.dir/BruteForce.c.o" \
"CMakeFiles/SudokuSolverX.dir/FileManip.c.o" \
"CMakeFiles/SudokuSolverX.dir/strategies.c.o" \
"CMakeFiles/SudokuSolverX.dir/hidden_singles.c.o" \
"CMakeFiles/SudokuSolverX.dir/naked_pairs.c.o" \
"CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.o" \
"CMakeFiles/SudokuSolverX.dir/box_reduction.c.o"

# External object files for target SudokuSolverX
SudokuSolverX_EXTERNAL_OBJECTS =

SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/main.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/Helpers.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/Consistency.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/tests.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/BruteForce.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/FileManip.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/strategies.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/hidden_singles.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/naked_pairs.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/pointing_pairs.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/box_reduction.c.o
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/build.make
SudokuSolverX.exe: CMakeFiles/SudokuSolverX.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable SudokuSolverX.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SudokuSolverX.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SudokuSolverX.dir/build: SudokuSolverX.exe

.PHONY : CMakeFiles/SudokuSolverX.dir/build

CMakeFiles/SudokuSolverX.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SudokuSolverX.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SudokuSolverX.dir/clean

CMakeFiles/SudokuSolverX.dir/depend:
	cd /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug /cygdrive/c/Users/hugod/CLionProjects/SudokuSolverX/cmake-build-debug/CMakeFiles/SudokuSolverX.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SudokuSolverX.dir/depend

