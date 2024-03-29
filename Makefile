BIN = bin/3DHouse
FLAGS = -Wall -g
INC = 
LIBS = -lglut -lGLU -lGL -lm 
LIBDIR = 
GCC = g++
OBJECTS = obj/voxels.o obj/createObjects.o obj/plants.o obj/main.o obj/scene.o obj/createScene.o obj/walls.o obj/camera.o obj/door.o obj/floor.o obj/furnitureS.o obj/furnitureC.o obj/furnitureSdb.o obj/furnitureCh.o

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

obj/door.o: src/Assets/door.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/floor.o: src/Assets/floor.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/furnitureS.o: src/Assets/furnitureS.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/furnitureC.o: src/Assets/furnitureC.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/furnitureSdb.o: src/Assets/furnitureSdb.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/furnitureCh.o: src/Assets/furnitureCh.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/scene.o: src/Scene/scene.cpp include/scene.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/createScene.o: src/Scene/createScene.cpp include/createScene.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/camera.o: src/camera.cpp include/camera.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/main.o: src/main.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;
