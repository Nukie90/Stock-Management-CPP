# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/premecwy/Downloads/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/premecwy/Downloads/Project/build

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o: project_autogen/mocs_compilation.cpp
CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/premecwy/Downloads/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o -MF CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o -c /Users/premecwy/Downloads/Project/build/project_autogen/mocs_compilation.cpp

CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/premecwy/Downloads/Project/build/project_autogen/mocs_compilation.cpp > CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.i

CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/premecwy/Downloads/Project/build/project_autogen/mocs_compilation.cpp -o CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.s

CMakeFiles/project.dir/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/main.cpp.o: /Users/premecwy/Downloads/Project/main.cpp
CMakeFiles/project.dir/main.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/premecwy/Downloads/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/main.cpp.o -MF CMakeFiles/project.dir/main.cpp.o.d -o CMakeFiles/project.dir/main.cpp.o -c /Users/premecwy/Downloads/Project/main.cpp

CMakeFiles/project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/premecwy/Downloads/Project/main.cpp > CMakeFiles/project.dir/main.cpp.i

CMakeFiles/project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/premecwy/Downloads/Project/main.cpp -o CMakeFiles/project.dir/main.cpp.s

CMakeFiles/project.dir/src/item.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/item.cpp.o: /Users/premecwy/Downloads/Project/src/item.cpp
CMakeFiles/project.dir/src/item.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/premecwy/Downloads/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project.dir/src/item.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/src/item.cpp.o -MF CMakeFiles/project.dir/src/item.cpp.o.d -o CMakeFiles/project.dir/src/item.cpp.o -c /Users/premecwy/Downloads/Project/src/item.cpp

CMakeFiles/project.dir/src/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/item.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/premecwy/Downloads/Project/src/item.cpp > CMakeFiles/project.dir/src/item.cpp.i

CMakeFiles/project.dir/src/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/item.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/premecwy/Downloads/Project/src/item.cpp -o CMakeFiles/project.dir/src/item.cpp.s

CMakeFiles/project.dir/src/product.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/product.cpp.o: /Users/premecwy/Downloads/Project/src/product.cpp
CMakeFiles/project.dir/src/product.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/premecwy/Downloads/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project.dir/src/product.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/src/product.cpp.o -MF CMakeFiles/project.dir/src/product.cpp.o.d -o CMakeFiles/project.dir/src/product.cpp.o -c /Users/premecwy/Downloads/Project/src/product.cpp

CMakeFiles/project.dir/src/product.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/product.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/premecwy/Downloads/Project/src/product.cpp > CMakeFiles/project.dir/src/product.cpp.i

CMakeFiles/project.dir/src/product.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/product.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/premecwy/Downloads/Project/src/product.cpp -o CMakeFiles/project.dir/src/product.cpp.s

CMakeFiles/project.dir/src/service.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/service.cpp.o: /Users/premecwy/Downloads/Project/src/service.cpp
CMakeFiles/project.dir/src/service.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/premecwy/Downloads/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project.dir/src/service.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/src/service.cpp.o -MF CMakeFiles/project.dir/src/service.cpp.o.d -o CMakeFiles/project.dir/src/service.cpp.o -c /Users/premecwy/Downloads/Project/src/service.cpp

CMakeFiles/project.dir/src/service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/service.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/premecwy/Downloads/Project/src/service.cpp > CMakeFiles/project.dir/src/service.cpp.i

CMakeFiles/project.dir/src/service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/service.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/premecwy/Downloads/Project/src/service.cpp -o CMakeFiles/project.dir/src/service.cpp.s

CMakeFiles/project.dir/src/storage.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/storage.cpp.o: /Users/premecwy/Downloads/Project/src/storage.cpp
CMakeFiles/project.dir/src/storage.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/premecwy/Downloads/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project.dir/src/storage.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/src/storage.cpp.o -MF CMakeFiles/project.dir/src/storage.cpp.o.d -o CMakeFiles/project.dir/src/storage.cpp.o -c /Users/premecwy/Downloads/Project/src/storage.cpp

CMakeFiles/project.dir/src/storage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/storage.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/premecwy/Downloads/Project/src/storage.cpp > CMakeFiles/project.dir/src/storage.cpp.i

CMakeFiles/project.dir/src/storage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/storage.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/premecwy/Downloads/Project/src/storage.cpp -o CMakeFiles/project.dir/src/storage.cpp.s

CMakeFiles/project.dir/src/invoice.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/invoice.cpp.o: /Users/premecwy/Downloads/Project/src/invoice.cpp
CMakeFiles/project.dir/src/invoice.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/premecwy/Downloads/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project.dir/src/invoice.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/src/invoice.cpp.o -MF CMakeFiles/project.dir/src/invoice.cpp.o.d -o CMakeFiles/project.dir/src/invoice.cpp.o -c /Users/premecwy/Downloads/Project/src/invoice.cpp

CMakeFiles/project.dir/src/invoice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/invoice.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/premecwy/Downloads/Project/src/invoice.cpp > CMakeFiles/project.dir/src/invoice.cpp.i

CMakeFiles/project.dir/src/invoice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/invoice.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/premecwy/Downloads/Project/src/invoice.cpp -o CMakeFiles/project.dir/src/invoice.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/project.dir/main.cpp.o" \
"CMakeFiles/project.dir/src/item.cpp.o" \
"CMakeFiles/project.dir/src/product.cpp.o" \
"CMakeFiles/project.dir/src/service.cpp.o" \
"CMakeFiles/project.dir/src/storage.cpp.o" \
"CMakeFiles/project.dir/src/invoice.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/project_autogen/mocs_compilation.cpp.o
project: CMakeFiles/project.dir/main.cpp.o
project: CMakeFiles/project.dir/src/item.cpp.o
project: CMakeFiles/project.dir/src/product.cpp.o
project: CMakeFiles/project.dir/src/service.cpp.o
project: CMakeFiles/project.dir/src/storage.cpp.o
project: CMakeFiles/project.dir/src/invoice.cpp.o
project: CMakeFiles/project.dir/build.make
project: /opt/homebrew/lib/QtSvgWidgets.framework/Versions/A/QtSvgWidgets
project: /opt/homebrew/lib/QtWidgets.framework/Versions/A/QtWidgets
project: /opt/homebrew/lib/QtSvg.framework/Versions/A/QtSvg
project: /opt/homebrew/lib/QtGui.framework/Versions/A/QtGui
project: /opt/homebrew/lib/QtCore.framework/Versions/A/QtCore
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/premecwy/Downloads/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project
.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /Users/premecwy/Downloads/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/premecwy/Downloads/Project /Users/premecwy/Downloads/Project /Users/premecwy/Downloads/Project/build /Users/premecwy/Downloads/Project/build /Users/premecwy/Downloads/Project/build/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend

