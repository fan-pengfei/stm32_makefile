#!Makefile
DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

SRC = $(wildcard $(DIR_SRC)/*.c)
OBJ = $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SRC))


TARGET = main

CC = gcc

main: $(OBJ)
	$(CC) $(OBJ) -o $(DIR_BIN)/$(TARGET)
	./bin/main.exe
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c	
	$(CC) -c $< -o $@ -I $(DIR_INC)
	
.PHONY:clean
clean:
	rm $(DIR_OBJ)/*
	rm $(DIR_BIN)/*
	
