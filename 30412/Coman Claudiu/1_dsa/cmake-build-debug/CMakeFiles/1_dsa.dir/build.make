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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\coman\CLionProjects\1_dsa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\coman\CLionProjects\1_dsa\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1_dsa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1_dsa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_dsa.dir/flags.make

CMakeFiles/1_dsa.dir/library.c.obj: CMakeFiles/1_dsa.dir/flags.make
CMakeFiles/1_dsa.dir/library.c.obj: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\coman\CLionProjects\1_dsa\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/1_dsa.dir/library.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\1_dsa.dir\library.c.obj   -c C:\Users\coman\CLionProjects\1_dsa\library.c

CMakeFiles/1_dsa.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/1_dsa.dir/library.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coman\CLionProjects\1_dsa\library.c > CMakeFiles\1_dsa.dir\library.c.i

CMakeFiles/1_dsa.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/1_dsa.dir/library.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coman\CLionProjects\1_dsa\library.c -o CMakeFiles\1_dsa.dir\library.c.s

# Object files for target 1_dsa
1_dsa_OBJECTS = \
"CMakeFiles/1_dsa.dir/library.c.obj"

# External object files for target 1_dsa
1_dsa_EXTERNAL_OBJECTS =

lib1_dsa.a: CMakeFiles/1_dsa.dir/library.c.obj
lib1_dsa.a: CMakeFiles/1_dsa.dir/build.make
lib1_dsa.a: CMakeFiles/1_dsa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\coman\CLionProjects\1_dsa\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library lib1_dsa.a"
	$(CMAKE_COMMAND) -P CMakeFiles\1_dsa.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1_dsa.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_dsa.dir/build: lib1_dsa.a

.PHONY : CMakeFiles/1_dsa.dir/build

CMakeFiles/1_dsa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1_dsa.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1_dsa.dir/clean

CMakeFiles/1_dsa.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\coman\CLionProjects\1_dsa C:\Users\coman\CLionProjects\1_dsa C:\Users\coman\CLionProjects\1_dsa\cmake-build-debug C:\Users\coman\CLionProjects\1_dsa\cmake-build-debug C:\Users\coman\CLionProjects\1_dsa\cmake-build-debug\CMakeFiles\1_dsa.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1_dsa.dir/depend
