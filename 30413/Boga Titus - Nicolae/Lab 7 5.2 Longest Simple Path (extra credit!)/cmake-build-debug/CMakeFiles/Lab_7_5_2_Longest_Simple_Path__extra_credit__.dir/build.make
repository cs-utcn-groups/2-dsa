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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/flags.make

CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.obj: CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/flags.make
CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir\main.c.obj   -c "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\main.c"

CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\main.c" > CMakeFiles\Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir\main.c.i

CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\main.c" -o CMakeFiles\Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir\main.c.s

# Object files for target Lab_7_5_2_Longest_Simple_Path__extra_credit__
Lab_7_5_2_Longest_Simple_Path__extra_credit___OBJECTS = \
"CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.obj"

# External object files for target Lab_7_5_2_Longest_Simple_Path__extra_credit__
Lab_7_5_2_Longest_Simple_Path__extra_credit___EXTERNAL_OBJECTS =

Lab_7_5_2_Longest_Simple_Path__extra_credit__.exe: CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/main.c.obj
Lab_7_5_2_Longest_Simple_Path__extra_credit__.exe: CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/build.make
Lab_7_5_2_Longest_Simple_Path__extra_credit__.exe: CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/linklibs.rsp
Lab_7_5_2_Longest_Simple_Path__extra_credit__.exe: CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/objects1.rsp
Lab_7_5_2_Longest_Simple_Path__extra_credit__.exe: CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab_7_5_2_Longest_Simple_Path__extra_credit__.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/build: Lab_7_5_2_Longest_Simple_Path__extra_credit__.exe

.PHONY : CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/build

CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/clean

CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)" "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)" "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\cmake-build-debug" "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\cmake-build-debug" "D:\Work\C++\Lab 7 5.2 Longest Simple Path (extra credit!)\cmake-build-debug\CMakeFiles\Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab_7_5_2_Longest_Simple_Path__extra_credit__.dir/depend

