# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/anton/Документы/OOP/life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/Документы/OOP/life/build

# Include any dependencies generated for this target.
include app/console_process_classes/CMakeFiles/console_processors_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include app/console_process_classes/CMakeFiles/console_processors_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include app/console_process_classes/CMakeFiles/console_processors_lib.dir/progress.make

# Include the compile flags for this target's objects.
include app/console_process_classes/CMakeFiles/console_processors_lib.dir/flags.make

app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o: app/console_process_classes/CMakeFiles/console_processors_lib.dir/flags.make
app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o: /home/anton/Документы/OOP/life/app/console_process_classes/console_input_processor.cpp
app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o: app/console_process_classes/CMakeFiles/console_processors_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Документы/OOP/life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o"
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o -MF CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o.d -o CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o -c /home/anton/Документы/OOP/life/app/console_process_classes/console_input_processor.cpp

app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.i"
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Документы/OOP/life/app/console_process_classes/console_input_processor.cpp > CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.i

app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.s"
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Документы/OOP/life/app/console_process_classes/console_input_processor.cpp -o CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.s

app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o: app/console_process_classes/CMakeFiles/console_processors_lib.dir/flags.make
app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o: /home/anton/Документы/OOP/life/app/console_process_classes/console_output_compiler.cpp
app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o: app/console_process_classes/CMakeFiles/console_processors_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Документы/OOP/life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o"
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o -MF CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o.d -o CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o -c /home/anton/Документы/OOP/life/app/console_process_classes/console_output_compiler.cpp

app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.i"
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Документы/OOP/life/app/console_process_classes/console_output_compiler.cpp > CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.i

app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.s"
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Документы/OOP/life/app/console_process_classes/console_output_compiler.cpp -o CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.s

# Object files for target console_processors_lib
console_processors_lib_OBJECTS = \
"CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o" \
"CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o"

# External object files for target console_processors_lib
console_processors_lib_EXTERNAL_OBJECTS =

app/console_process_classes/libconsole_processors_lib.a: app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_input_processor.cpp.o
app/console_process_classes/libconsole_processors_lib.a: app/console_process_classes/CMakeFiles/console_processors_lib.dir/console_output_compiler.cpp.o
app/console_process_classes/libconsole_processors_lib.a: app/console_process_classes/CMakeFiles/console_processors_lib.dir/build.make
app/console_process_classes/libconsole_processors_lib.a: app/console_process_classes/CMakeFiles/console_processors_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anton/Документы/OOP/life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libconsole_processors_lib.a"
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && $(CMAKE_COMMAND) -P CMakeFiles/console_processors_lib.dir/cmake_clean_target.cmake
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/console_processors_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/console_process_classes/CMakeFiles/console_processors_lib.dir/build: app/console_process_classes/libconsole_processors_lib.a
.PHONY : app/console_process_classes/CMakeFiles/console_processors_lib.dir/build

app/console_process_classes/CMakeFiles/console_processors_lib.dir/clean:
	cd /home/anton/Документы/OOP/life/build/app/console_process_classes && $(CMAKE_COMMAND) -P CMakeFiles/console_processors_lib.dir/cmake_clean.cmake
.PHONY : app/console_process_classes/CMakeFiles/console_processors_lib.dir/clean

app/console_process_classes/CMakeFiles/console_processors_lib.dir/depend:
	cd /home/anton/Документы/OOP/life/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/Документы/OOP/life /home/anton/Документы/OOP/life/app/console_process_classes /home/anton/Документы/OOP/life/build /home/anton/Документы/OOP/life/build/app/console_process_classes /home/anton/Документы/OOP/life/build/app/console_process_classes/CMakeFiles/console_processors_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : app/console_process_classes/CMakeFiles/console_processors_lib.dir/depend

