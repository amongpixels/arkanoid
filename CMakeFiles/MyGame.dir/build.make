# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dragomir/git/arkanoid_default

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dragomir/git/arkanoid_default

# Include any dependencies generated for this target.
include CMakeFiles/MyGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyGame.dir/flags.make

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o: Classes/AppDelegate.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dragomir/git/arkanoid_default/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o -c /home/dragomir/git/arkanoid_default/Classes/AppDelegate.cpp

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dragomir/git/arkanoid_default/Classes/AppDelegate.cpp > CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dragomir/git/arkanoid_default/Classes/AppDelegate.cpp -o CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o

CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o: Classes/game/Paddle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dragomir/git/arkanoid_default/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o -c /home/dragomir/git/arkanoid_default/Classes/game/Paddle.cpp

CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dragomir/git/arkanoid_default/Classes/game/Paddle.cpp > CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.i

CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dragomir/git/arkanoid_default/Classes/game/Paddle.cpp -o CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.s

CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o

CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o: Classes/game/Ball.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dragomir/git/arkanoid_default/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o -c /home/dragomir/git/arkanoid_default/Classes/game/Ball.cpp

CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dragomir/git/arkanoid_default/Classes/game/Ball.cpp > CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.i

CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dragomir/git/arkanoid_default/Classes/game/Ball.cpp -o CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.s

CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o

CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o: Classes/game/Bricks.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dragomir/git/arkanoid_default/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o -c /home/dragomir/git/arkanoid_default/Classes/game/Bricks.cpp

CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dragomir/git/arkanoid_default/Classes/game/Bricks.cpp > CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.i

CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dragomir/git/arkanoid_default/Classes/game/Bricks.cpp -o CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.s

CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o

CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o: Classes/scenes/LevelScene.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dragomir/git/arkanoid_default/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o -c /home/dragomir/git/arkanoid_default/Classes/scenes/LevelScene.cpp

CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dragomir/git/arkanoid_default/Classes/scenes/LevelScene.cpp > CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.i

CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dragomir/git/arkanoid_default/Classes/scenes/LevelScene.cpp -o CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.s

CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/proj.linux/main.cpp.o: proj.linux/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dragomir/git/arkanoid_default/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/proj.linux/main.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/proj.linux/main.cpp.o -c /home/dragomir/git/arkanoid_default/proj.linux/main.cpp

CMakeFiles/MyGame.dir/proj.linux/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/proj.linux/main.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dragomir/git/arkanoid_default/proj.linux/main.cpp > CMakeFiles/MyGame.dir/proj.linux/main.cpp.i

CMakeFiles/MyGame.dir/proj.linux/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/proj.linux/main.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dragomir/git/arkanoid_default/proj.linux/main.cpp -o CMakeFiles/MyGame.dir/proj.linux/main.cpp.s

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides.build: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o

# Object files for target MyGame
MyGame_OBJECTS = \
"CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o" \
"CMakeFiles/MyGame.dir/proj.linux/main.cpp.o"

# External object files for target MyGame
MyGame_EXTERNAL_OBJECTS =

bin/MyGame: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/build.make
bin/MyGame: lib/libcocos2d.a
bin/MyGame: /usr/lib64/libGLU.so
bin/MyGame: /usr/lib64/libGL.so
bin/MyGame: /usr/lib64/libSM.so
bin/MyGame: /usr/lib64/libICE.so
bin/MyGame: /usr/lib64/libX11.so
bin/MyGame: /usr/lib64/libXext.so
bin/MyGame: /usr/lib64/libGLEW.so
bin/MyGame: cocos2d/external/linux-specific/fmod/prebuilt/64-bit/libfmodex64.so
bin/MyGame: cocos2d/external/linux-specific/fmod/prebuilt/64-bit/libfmodexL64.so
bin/MyGame: lib/libunzip.a
bin/MyGame: /usr/lib64/libz.so
bin/MyGame: cocos2d/external/jpeg/prebuilt/linux/64-bit/libjpeg.a
bin/MyGame: /usr/lib64/libpng.so
bin/MyGame: /usr/lib64/libz.so
bin/MyGame: cocos2d/external/jpeg/prebuilt/linux/64-bit/libjpeg.a
bin/MyGame: /usr/lib64/libpng.so
bin/MyGame: cocos2d/external/tiff/prebuilt/linux/64-bit/libtiff.a
bin/MyGame: lib/libtinyxml2.a
bin/MyGame: cocos2d/external/freetype2/prebuilt/linux/64-bit/libfreetype.a
bin/MyGame: cocos2d/external/websockets/prebuilt/linux/64-bit/libwebsockets.a
bin/MyGame: lib/libxxhash.a
bin/MyGame: cocos2d/external/webp/prebuilt/linux/64-bit/libwebp.a
bin/MyGame: cocos2d/external/chipmunk/prebuilt/linux/64-bit/libchipmunk.a
bin/MyGame: CMakeFiles/MyGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/MyGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyGame.dir/build: bin/MyGame
.PHONY : CMakeFiles/MyGame.dir/build

CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/game/Paddle.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/game/Ball.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/game/Bricks.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/scenes/LevelScene.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires
.PHONY : CMakeFiles/MyGame.dir/requires

CMakeFiles/MyGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyGame.dir/clean

CMakeFiles/MyGame.dir/depend:
	cd /home/dragomir/git/arkanoid_default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dragomir/git/arkanoid_default /home/dragomir/git/arkanoid_default /home/dragomir/git/arkanoid_default /home/dragomir/git/arkanoid_default /home/dragomir/git/arkanoid_default/CMakeFiles/MyGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyGame.dir/depend

