# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Downloads\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Downloads\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/aeda1718_ci01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aeda1718_ci01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aeda1718_ci01.dir/flags.make

CMakeFiles/aeda1718_ci01.dir/Test.cpp.obj: CMakeFiles/aeda1718_ci01.dir/flags.make
CMakeFiles/aeda1718_ci01.dir/Test.cpp.obj: CMakeFiles/aeda1718_ci01.dir/includes_CXX.rsp
CMakeFiles/aeda1718_ci01.dir/Test.cpp.obj: ../Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aeda1718_ci01.dir/Test.cpp.obj"
	D:\Downloads\mingw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\aeda1718_ci01.dir\Test.cpp.obj -c "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\Test.cpp"

CMakeFiles/aeda1718_ci01.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1718_ci01.dir/Test.cpp.i"
	D:\Downloads\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\Test.cpp" > CMakeFiles\aeda1718_ci01.dir\Test.cpp.i

CMakeFiles/aeda1718_ci01.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1718_ci01.dir/Test.cpp.s"
	D:\Downloads\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\Test.cpp" -o CMakeFiles\aeda1718_ci01.dir\Test.cpp.s

CMakeFiles/aeda1718_ci01.dir/Car.cpp.obj: CMakeFiles/aeda1718_ci01.dir/flags.make
CMakeFiles/aeda1718_ci01.dir/Car.cpp.obj: CMakeFiles/aeda1718_ci01.dir/includes_CXX.rsp
CMakeFiles/aeda1718_ci01.dir/Car.cpp.obj: ../Car.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aeda1718_ci01.dir/Car.cpp.obj"
	D:\Downloads\mingw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\aeda1718_ci01.dir\Car.cpp.obj -c "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\Car.cpp"

CMakeFiles/aeda1718_ci01.dir/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1718_ci01.dir/Car.cpp.i"
	D:\Downloads\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\Car.cpp" > CMakeFiles\aeda1718_ci01.dir\Car.cpp.i

CMakeFiles/aeda1718_ci01.dir/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1718_ci01.dir/Car.cpp.s"
	D:\Downloads\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\Car.cpp" -o CMakeFiles\aeda1718_ci01.dir\Car.cpp.s

# Object files for target aeda1718_ci01
aeda1718_ci01_OBJECTS = \
"CMakeFiles/aeda1718_ci01.dir/Test.cpp.obj" \
"CMakeFiles/aeda1718_ci01.dir/Car.cpp.obj"

# External object files for target aeda1718_ci01
aeda1718_ci01_EXTERNAL_OBJECTS =

aeda1718_ci01.exe: CMakeFiles/aeda1718_ci01.dir/Test.cpp.obj
aeda1718_ci01.exe: CMakeFiles/aeda1718_ci01.dir/Car.cpp.obj
aeda1718_ci01.exe: CMakeFiles/aeda1718_ci01.dir/build.make
aeda1718_ci01.exe: lib/libgtestd.a
aeda1718_ci01.exe: lib/libgtest_maind.a
aeda1718_ci01.exe: lib/libgtestd.a
aeda1718_ci01.exe: CMakeFiles/aeda1718_ci01.dir/linklibs.rsp
aeda1718_ci01.exe: CMakeFiles/aeda1718_ci01.dir/objects1.rsp
aeda1718_ci01.exe: CMakeFiles/aeda1718_ci01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable aeda1718_ci01.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\aeda1718_ci01.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aeda1718_ci01.dir/build: aeda1718_ci01.exe

.PHONY : CMakeFiles/aeda1718_ci01.dir/build

CMakeFiles/aeda1718_ci01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\aeda1718_ci01.dir\cmake_clean.cmake
.PHONY : CMakeFiles/aeda1718_ci01.dir/clean

CMakeFiles/aeda1718_ci01.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros" "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros" "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\cmake-build-debug" "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\cmake-build-debug" "D:\Documentos\FEUP\2 ano\1 semestre\Algoritmos\Teste 1\2017\2017_ficheiros\cmake-build-debug\CMakeFiles\aeda1718_ci01.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/aeda1718_ci01.dir/depend
