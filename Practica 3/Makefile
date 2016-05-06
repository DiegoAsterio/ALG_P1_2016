SRC = Algoritmos
INC = Algoritmos
OBJ = ./obj
BIN = ./bin
CXX = g++ -fopenmp
CPPFLAGS = -Wall -O3 -fopenmp -g -I$(INC)/ -c


all: $(BIN)/tsp_main

# ************ Compilación de módulos ************

$(BIN)/tsp_main: $(OBJ)/TSP.o $(OBJ)/tsp_main.o $(INC)/TSP.h
	$(CXX) -o $(BIN)/tsp_main $(OBJ)/tsp_main.o $(OBJ)/TSP.o

$(OBJ)/tsp_main.o: $(SRC)/tsp_main.cpp $(INC)/TSP.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/tsp_main.o $(SRC)/tsp_main.cpp

$(OBJ)/TSP.o: $(SRC)/TSP.cpp $(INC)/TSP.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/TSP.o $(SRC)/TSP.cpp
