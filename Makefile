BIN = bin/3DHouse
FLAGS = -Wall -g
INC = 
LIBS = -lglut -lGLU -lGL -lm -lSDL -lSDL_image
LIBDIR = 
GCC = g++
OBJECTS = obj/voxels.o obj/createObjects.o obj/house.o obj/main.o 

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/voxels.o: src/voxels.cpp include/voxels.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/createObjects.o: src/Scene/createObjects.cpp include/createObjects.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/house.o: src/Assets/house.cpp include/assets.hpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/main.o: src/main.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;
