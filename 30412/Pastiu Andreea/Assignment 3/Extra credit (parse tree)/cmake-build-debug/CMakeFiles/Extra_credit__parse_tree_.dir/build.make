# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Extra_credit__parse_tree_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Extra_credit__parse_tree_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Extra_credit__parse_tree_.dir/flags.make

CMakeFiles/Extra_credit__parse_tree_.dir/main.c.obj: CMakeFiles/Extra_credit__parse_tree_.dir/flags.make
CMakeFiles/Extra_credit__parse_tree_.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Extra_credit__parse_tree_.dir/main.c.obj"
	C:\Users\Andreea\.CLion2019.2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Extra_credit__parse_tree_.dir\main.c.obj   -c "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\main.c"

CMakeFiles/Extra_credit__parse_tree_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Extra_credit__parse_tree_.dir/main.c.i"
	C:\Users\Andreea\.CLion2019.2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\main.c" > CMakeFiles\Extra_credit__parse_tree_.dir\main.c.i

CMakeFiles/Extra_credit__parse_tree_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Extra_credit__parse_tree_.dir/main.c.s"
	C:\Users\Andreea\.CLion2019.2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\main.c" -o CMakeFiles\Extra_credit__parse_tree_.dir\main.c.s

# Object files for target Extra_credit__parse_tree_
Extra_credit__parse_tree__OBJECTS = \
"CMakeFiles/Extra_credit__parse_tree_.dir/main.c.obj"

# External object files for target Extra_credit__parse_tree_
Extra_credit__parse_tree__EXTERNAL_OBJECTS =

Extra_credit__parse_tree_.exe: CMakeFiles/Extra_credit__parse_tree_.dir/main.c.obj
Extra_credit__parse_tree_.exe: CMakeFiles/Extra_credit__parse_tree_.dir/build.make
Extra_credit__parse_tree_.exe: CMakeFiles/Extra_credit__parse_tree_.dir/linklibs.rsp
Extra_credit__parse_tree_.exe: CMakeFiles/Extra_credit__parse_tree_.dir/objects1.rsp
Extra_credit__parse_tree_.exe: CMakeFiles/Extra_credit__parse_tree_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Extra_credit__parse_tree_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Extra_credit__parse_tree_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Extra_credit__parse_tree_.dir/build: Extra_credit__parse_tree_.exe

.PHONY : CMakeFiles/Extra_credit__parse_tree_.dir/build

CMakeFiles/Extra_credit__parse_tree_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Extra_credit__parse_tree_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Extra_credit__parse_tree_.dir/clean

CMakeFiles/Extra_credit__parse_tree_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)" "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)" "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\cmake-build-debug" "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\cmake-build-debug" "D:\documente scoala\Facultate\SEM2\CP\DSA\2-dsa\30412\Pastiu Andreea\Assignment 3\Extra credit (parse tree)\cmake-build-debug\CMakeFiles\Extra_credit__parse_tree_.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Extra_credit__parse_tree_.dir/depend
