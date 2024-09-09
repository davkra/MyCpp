CC := g++
CFLAGS := -Wall -g -std=c++11

ODIR := ./obj
SDIR := ./src
IDIR := ./src/inc

BIN := $(patsubst %.cpp, %, $(wildcard *.cpp))
DEP := $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(wildcard $(SDIR)/*.cpp))
OBJ := $(DEP) $(patsubst %, $(ODIR)/%.o, $(BIN))

all: $(ODIR) $(OBJ) $(BIN)

rebuild: clean all

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

$(ODIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(IDIR)

%: $(DEP) $(ODIR)/%.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rfv $(ODIR) *.o $(BIN)
