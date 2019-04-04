
CC = g++
CCFLAGS = -Wall -Wextra -Werror -std=c++17 -o3

PATH_SRC = ./src
PATH_INC = ./include
PATH_BIN = ./bin

.PHONY: all
all:
	mkdir -p $(PATH_BIN)
	$(CC) -I $(PATH_INC) $(CCFLAGS) $(PATH_SRC)/main.cpp -o $(PATH_BIN)/main.exe

.PHONY: clean
clean:
	rm -rf ./bin
