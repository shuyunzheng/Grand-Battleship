GPP = g++
CFLAGS = -std=c++11 -Wall -I /usr/include/allegro5/
LIBDIR = /usr/lib64/
LNFLAGS = -lallegro -lallegro_primitives -lallegro_image

#This finds all your cc files and places then into SRC. It's equivalent would be
# SRC = src/main.cc src/folder1/func1.cc src/folder1/func2.cc src/folder2/func3.cc

SRC = $(shell find . -name *.cpp)

#This tells Make that somewhere below, you are going to convert all your source into 
#objects, so this is like:
# OBJ =  src/main.o src/folder1/func1.o src/folder1/func2.o src/folder2/func3.o

OBJ = $(SRC:%.cc=%.o)

#Tells make your binary is called battleship and it should be in bin/
BIN = bin/battleship

# all is the target (you would run make all from the command line). 'all' is dependent
# on $(BIN)
all: $(BIN)

#$(BIN) is dependent on objects
$(BIN): $(OBJ)
	$(GPP) $(CFLAGS) -L $(LIBDIR) -o $@ $^ $(LNFLAGS)

#each object file is dependent on its source file, and whenever make needs to create
# an object file, to follow this rule:
%.o : %.cc
	$(GPP) $(CFLAGS) -c $^
