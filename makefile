EXE     = engine
LIBS    = -lglfw -lGLEW	-lSOIL -lGL
SOURCE  = src/*.cpp src/math/*.cpp src/scene/*.cpp src/hardware/*.cpp
FLAGS   = -std=c++11
INCLUDE = -I./include/

all:
	exit

debian:
	test -s /usr/lib/libglfw.so || { apt-get install libglfw-dev; }
	test -s /usr/lib/libGLEW.so || { test -s /usr/lib/x86_64-linux-gnu/libGLEW.so || { apt-get install libglew-dev; }; }
	test -s /usr/lib/libSOIL.a  || { apt-get install libsoil-dev; }


	g++ $(FLAGS) $(INCLUDE) $(SOURCE) -o $(EXE) $(LIBS)
