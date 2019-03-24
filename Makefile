
CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -g3

PATH_SRC = ./src
PATH_INC = ./include
PATH_BIN = ./bin
PATH_TEST = ./test

.PHONY: all
all:
	mkdir -p $(PATH_BIN)
	$(CC) -I $(PATH_INC) $(CCFLAGS) $(PATH_TEST)/main.cpp -o $(PATH_BIN)/main.exe

.PHONY: clean
clean:
	rm -rf ./bin
