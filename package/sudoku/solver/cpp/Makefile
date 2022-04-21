CPP = g++
CPPFLAGS = -Wextra -Wall -Werror -pedantic
SRC = src/test.cpp $(wildcard src/*/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = test

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -g -c $< -o $@

$(BIN): $(OBJ)
	$(CPP) $(OBJ) -o $(BIN)

.PHONY: clean
clean:
	@rm $(OBJ)
	@rm $(BIN)
