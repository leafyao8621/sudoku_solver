CC = gcc
SRC = src/test.c $(wildcard src/*/*.c)
OBJ = $(SRC:.c=.o)
BIN = test

%.o: %.c
	$(CC) -g -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

.PHONY: clean
	@rm $(OBJ)
	@rm $(BIN)
