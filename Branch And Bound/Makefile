CC = g++
CPPFLAGS = -Wall -g -I$(INCLUDE) -I$(SRC) -std=c++11
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)
MAIN_OBJECTS := $(patsubst $(SRC)/mains/%.cpp, $(OBJ)/%.o, $(wildcard $(SRC)/mains/*.cpp))

all: $(BIN)/sentarBNB

$(BIN)/sentarBNB: $(OBJECTS) $(OBJ)/sentarBNB.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

$(MAIN_OBJECTS): $(OBJ)/%.o: $(SRC)/mains/%.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

doc:
	doxygen $(DOC)/doxys/Doxyfile

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc
