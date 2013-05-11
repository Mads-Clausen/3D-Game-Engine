EXE     = engine
LIBS    = -lglfw -lGLEW	-lGL
SOURCE  = src/*.cpp src/math/*.cpp src/scene/*.cpp
INCLUDE = -I./include/

all:
	test -s /usr/lib/libglfw.so || { apt-get install libglfw-dev; }
	test -s /usr/lib/libGLEW.so || { test -s /usr/lib/x86_64-linux-gnu/libGLEW.so || { apt-get install libglew-dev; }; }

	g++ $(INCLUDE) $(SOURCE) -o $(EXE) $(LIBS)
