# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\CODE\SEM V\MHE\LAB03"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CODE\SEM V\MHE\LAB03\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LAB03.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LAB03.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LAB03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LAB03.dir/flags.make

CMakeFiles/LAB03.dir/main.cpp.obj: CMakeFiles/LAB03.dir/flags.make
CMakeFiles/LAB03.dir/main.cpp.obj: ../main.cpp
CMakeFiles/LAB03.dir/main.cpp.obj: CMakeFiles/LAB03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CODE\SEM V\MHE\LAB03\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LAB03.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LAB03.dir/main.cpp.obj -MF CMakeFiles\LAB03.dir\main.cpp.obj.d -o CMakeFiles\LAB03.dir\main.cpp.obj -c "E:\CODE\SEM V\MHE\LAB03\main.cpp"

CMakeFiles/LAB03.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB03.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\CODE\SEM V\MHE\LAB03\main.cpp" > CMakeFiles\LAB03.dir\main.cpp.i

CMakeFiles/LAB03.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB03.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\CODE\SEM V\MHE\LAB03\main.cpp" -o CMakeFiles\LAB03.dir\main.cpp.s

# Object files for target LAB03
LAB03_OBJECTS = \
"CMakeFiles/LAB03.dir/main.cpp.obj"

# External object files for target LAB03
LAB03_EXTERNAL_OBJECTS =

LAB03.exe: CMakeFiles/LAB03.dir/main.cpp.obj
LAB03.exe: CMakeFiles/LAB03.dir/build.make
LAB03.exe: CMakeFiles/LAB03.dir/linklibs.rsp
LAB03.exe: CMakeFiles/LAB03.dir/objects1.rsp
LAB03.exe: CMakeFiles/LAB03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CODE\SEM V\MHE\LAB03\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LAB03.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LAB03.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LAB03.dir/build: LAB03.exe
.PHONY : CMakeFiles/LAB03.dir/build

CMakeFiles/LAB03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LAB03.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LAB03.dir/clean

CMakeFiles/LAB03.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CODE\SEM V\MHE\LAB03" "E:\CODE\SEM V\MHE\LAB03" "E:\CODE\SEM V\MHE\LAB03\cmake-build-debug" "E:\CODE\SEM V\MHE\LAB03\cmake-build-debug" "E:\CODE\SEM V\MHE\LAB03\cmake-build-debug\CMakeFiles\LAB03.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LAB03.dir/depend

