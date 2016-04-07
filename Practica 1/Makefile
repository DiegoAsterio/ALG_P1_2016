################################################################################
# Makefile
################################################################################

STUDDATA = $(wildcard data/*/*.dat)
STUDGRPH = $(wildcard grphx/*/*.{jpg,png})

BIN = bin

SRC = $(wildcard src/*.cpp)
EXE = $(basename $(SRC))
ALG = $(wildcard *.cpp)

CXXFLAGS = -std=gnu++0x

default: $(EXE)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(patsubst src%,bin%,$(basename $< ))

clean:
	$(RM) -v $(BIN)/*

mrproper: clean
	$(RM) -v $(BIN)/* $(STUDDATA) $(STUDGRPH)

.PHONY: clean
.PRECIOUS: $(LOG)
.NOEXPORT:

################################################################################
