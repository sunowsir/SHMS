# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/SHMS.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/SHMS.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/SHMS.dir/flags.make

lib/CMakeFiles/SHMS.dir/src/Get_conf.c.o: lib/CMakeFiles/SHMS.dir/flags.make
lib/CMakeFiles/SHMS.dir/src/Get_conf.c.o: ../lib/src/Get_conf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/SHMS.dir/src/Get_conf.c.o"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SHMS.dir/src/Get_conf.c.o -c /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/Get_conf.c

lib/CMakeFiles/SHMS.dir/src/Get_conf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SHMS.dir/src/Get_conf.c.i"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/Get_conf.c > CMakeFiles/SHMS.dir/src/Get_conf.c.i

lib/CMakeFiles/SHMS.dir/src/Get_conf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SHMS.dir/src/Get_conf.c.s"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/Get_conf.c -o CMakeFiles/SHMS.dir/src/Get_conf.c.s

lib/CMakeFiles/SHMS.dir/src/StrtoInt.c.o: lib/CMakeFiles/SHMS.dir/flags.make
lib/CMakeFiles/SHMS.dir/src/StrtoInt.c.o: ../lib/src/StrtoInt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/CMakeFiles/SHMS.dir/src/StrtoInt.c.o"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SHMS.dir/src/StrtoInt.c.o -c /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/StrtoInt.c

lib/CMakeFiles/SHMS.dir/src/StrtoInt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SHMS.dir/src/StrtoInt.c.i"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/StrtoInt.c > CMakeFiles/SHMS.dir/src/StrtoInt.c.i

lib/CMakeFiles/SHMS.dir/src/StrtoInt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SHMS.dir/src/StrtoInt.c.s"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/StrtoInt.c -o CMakeFiles/SHMS.dir/src/StrtoInt.c.s

lib/CMakeFiles/SHMS.dir/src/sockFrame.c.o: lib/CMakeFiles/SHMS.dir/flags.make
lib/CMakeFiles/SHMS.dir/src/sockFrame.c.o: ../lib/src/sockFrame.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/CMakeFiles/SHMS.dir/src/sockFrame.c.o"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SHMS.dir/src/sockFrame.c.o -c /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/sockFrame.c

lib/CMakeFiles/SHMS.dir/src/sockFrame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SHMS.dir/src/sockFrame.c.i"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/sockFrame.c > CMakeFiles/SHMS.dir/src/sockFrame.c.i

lib/CMakeFiles/SHMS.dir/src/sockFrame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SHMS.dir/src/sockFrame.c.s"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/sockFrame.c -o CMakeFiles/SHMS.dir/src/sockFrame.c.s

lib/CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.o: lib/CMakeFiles/SHMS.dir/flags.make
lib/CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.o: ../lib/src/Write_Pi_Log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object lib/CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.o"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.o -c /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/Write_Pi_Log.c

lib/CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.i"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/Write_Pi_Log.c > CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.i

lib/CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.s"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib/src/Write_Pi_Log.c -o CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.s

# Object files for target SHMS
SHMS_OBJECTS = \
"CMakeFiles/SHMS.dir/src/Get_conf.c.o" \
"CMakeFiles/SHMS.dir/src/StrtoInt.c.o" \
"CMakeFiles/SHMS.dir/src/sockFrame.c.o" \
"CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.o"

# External object files for target SHMS
SHMS_EXTERNAL_OBJECTS =

lib/libSHMS.a: lib/CMakeFiles/SHMS.dir/src/Get_conf.c.o
lib/libSHMS.a: lib/CMakeFiles/SHMS.dir/src/StrtoInt.c.o
lib/libSHMS.a: lib/CMakeFiles/SHMS.dir/src/sockFrame.c.o
lib/libSHMS.a: lib/CMakeFiles/SHMS.dir/src/Write_Pi_Log.c.o
lib/libSHMS.a: lib/CMakeFiles/SHMS.dir/build.make
lib/libSHMS.a: lib/CMakeFiles/SHMS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libSHMS.a"
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/SHMS.dir/cmake_clean_target.cmake
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SHMS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/SHMS.dir/build: lib/libSHMS.a

.PHONY : lib/CMakeFiles/SHMS.dir/build

lib/CMakeFiles/SHMS.dir/clean:
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/SHMS.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/SHMS.dir/clean

lib/CMakeFiles/SHMS.dir/depend:
	cd /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/lib /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib /home/sunowsir/Code/1.GitHub/1.MyPorject/SHMS/Master/build/lib/CMakeFiles/SHMS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/SHMS.dir/depend

