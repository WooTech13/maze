
SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib
INC_DIR = include

CC      = gcc
LDFLAGS = -L$(LIB_DIR) -lm
CFLAGS  = -I$(INC_DIR) -fPIC

all: clean prog

prog : $(BIN_DIR)/maze.o $(LIB_DIR)/libmat.a
	$(CC) -o prog $(BIN_DIR)/maze.o $(BIN_DIR)/generate.o $(BIN_DIR)/display.o $(BIN_DIR)/util.o $(LDFLAGS)

$(LIB_DIR)/libmat.a : $(BIN_DIR)/generate.o $(BIN_DIR)/display.o $(BIN_DIR)/util.o
	ar rs $@ $^

$(BIN_DIR)/maze.o : $(SRC_DIR)/maze.c $(INC_DIR)/maze.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/maze.c -o $(BIN_DIR)/maze.o

$(BIN_DIR)/generate.o : $(SRC_DIR)/generate.c $(INC_DIR)/generate.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/generate.c -o $(BIN_DIR)/generate.o

$(BIN_DIR)/display.o : $(SRC_DIR)/display.c $(INC_DIR)/display.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/display.c -o $(BIN_DIR)/display.o

$(BIN_DIR)/util.o : $(SRC_DIR)/util.c $(INC_DIR)/util.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/util.c -o $(BIN_DIR)/util.o

clean: 
	rm -rRf prog $(BIN_DIR)/* $(LIB_DIR)/* html/* latex/*
	mkdir -p $(BIN_DIR)
	mkdir -p $(LIB_DIR)

doc :
	doxygen Doxyfile

.PHONY : clean doc
