# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL

# Include any dependencies generated for this target.
include TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/depend.make

# Include the progress variables for this target.
include TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/progress.make

# Include the compile flags for this target's objects.
include TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/flags.make

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o: TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/flags.make
TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o: TP2/exo2_triangle_couleurs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o"
	cd /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o -c /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2/exo2_triangle_couleurs.cpp

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.i"
	cd /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2/exo2_triangle_couleurs.cpp > CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.i

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.s"
	cd /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2/exo2_triangle_couleurs.cpp -o CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.s

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o.requires:

.PHONY : TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o.requires

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o.provides: TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o.requires
	$(MAKE) -f TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/build.make TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o.provides.build
.PHONY : TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o.provides

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o.provides.build: TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o


# Object files for target TP2_exo2_triangle_couleurs
TP2_exo2_triangle_couleurs_OBJECTS = \
"CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o"

# External object files for target TP2_exo2_triangle_couleurs
TP2_exo2_triangle_couleurs_EXTERNAL_OBJECTS =

TP2/TP2_exo2_triangle_couleurs: TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o
TP2/TP2_exo2_triangle_couleurs: TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/build.make
TP2/TP2_exo2_triangle_couleurs: glimac/libglimac.a
TP2/TP2_exo2_triangle_couleurs: /usr/lib/x86_64-linux-gnu/libGL.so
TP2/TP2_exo2_triangle_couleurs: /usr/lib/x86_64-linux-gnu/libGLU.so
TP2/TP2_exo2_triangle_couleurs: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP2/TP2_exo2_triangle_couleurs: TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP2_exo2_triangle_couleurs"
	cd /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP2_exo2_triangle_couleurs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/build: TP2/TP2_exo2_triangle_couleurs

.PHONY : TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/build

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/requires: TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/exo2_triangle_couleurs.cpp.o.requires

.PHONY : TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/requires

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/clean:
	cd /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2 && $(CMAKE_COMMAND) -P CMakeFiles/TP2_exo2_triangle_couleurs.dir/cmake_clean.cmake
.PHONY : TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/clean

TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/depend:
	cd /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2 /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2 /home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP2/CMakeFiles/TP2_exo2_triangle_couleurs.dir/depend
