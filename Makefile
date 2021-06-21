BIN = bin/3DHouse
FLAGS = -Wall -g
INC = 
LIBS = -lglut -lGLU -lGL -lm 
LIBDIR = 
GCC = g++
OBJECTS = obj/voxels.o obj/createObjects.o obj/plants.o obj/main.o obj/scene.o obj/createScene.o obj/walls.o obj/camera.o

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/voxels.o: src/voxels.cpp include/voxels.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/createObjects.o: src/Scene/createObjects.cpp include/createObjects.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/plants.o: src/Assets/plants.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/walls.o: src/Assets/walls.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/scene.o: src/Scene/scene.cpp include/scene.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/createScene.o: src/Scene/createScene.cpp include/createScene.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/camera.o: src/camera.cpp include/camera.hpp include/spline.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/main.o: src/main.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;
