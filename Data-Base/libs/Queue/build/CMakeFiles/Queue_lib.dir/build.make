# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = C:\Anaconda3\Lib\site-packages\cmake\data\bin\cmake.exe

# The command to remove a file.
RM = C:\Anaconda3\Lib\site-packages\cmake\data\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\WX_CAREER\Projects\DataBase_Project\libs\Queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\build

# Include any dependencies generated for this target.
include CMakeFiles/Queue_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Queue_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Queue_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Queue_lib.dir/flags.make

CMakeFiles/Queue_lib.dir/src/Queue.c.obj: CMakeFiles/Queue_lib.dir/flags.make
CMakeFiles/Queue_lib.dir/src/Queue.c.obj: ../src/Queue.c
CMakeFiles/Queue_lib.dir/src/Queue.c.obj: CMakeFiles/Queue_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Queue_lib.dir/src/Queue.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Queue_lib.dir/src/Queue.c.obj -MF CMakeFiles\Queue_lib.dir\src\Queue.c.obj.d -o CMakeFiles\Queue_lib.dir\src\Queue.c.obj -c H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\src\Queue.c

CMakeFiles/Queue_lib.dir/src/Queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Queue_lib.dir/src/Queue.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\src\Queue.c > CMakeFiles\Queue_lib.dir\src\Queue.c.i

CMakeFiles/Queue_lib.dir/src/Queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Queue_lib.dir/src/Queue.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\src\Queue.c -o CMakeFiles\Queue_lib.dir\src\Queue.c.s

# Object files for target Queue_lib
Queue_lib_OBJECTS = \
"CMakeFiles/Queue_lib.dir/src/Queue.c.obj"

# External object files for target Queue_lib
Queue_lib_EXTERNAL_OBJECTS =

libQueue_lib.a: CMakeFiles/Queue_lib.dir/src/Queue.c.obj
libQueue_lib.a: CMakeFiles/Queue_lib.dir/build.make
libQueue_lib.a: CMakeFiles/Queue_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libQueue_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\Queue_lib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Queue_lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Queue_lib.dir/build: libQueue_lib.a
.PHONY : CMakeFiles/Queue_lib.dir/build

CMakeFiles/Queue_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Queue_lib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Queue_lib.dir/clean

CMakeFiles/Queue_lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\WX_CAREER\Projects\DataBase_Project\libs\Queue H:\WX_CAREER\Projects\DataBase_Project\libs\Queue H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\build H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\build H:\WX_CAREER\Projects\DataBase_Project\libs\Queue\build\CMakeFiles\Queue_lib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Queue_lib.dir/depend
