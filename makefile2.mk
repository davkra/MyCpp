CC := g++
CFLAGS := -Wall -g -std=c++11

ODIR := ./obj
SDIR := ./src
IDIR := ./src/inc

DEP := $(ODIR)/print.o
OBJ := $(DEP) $(ODIR)/main.o $(ODIR)/test.o
BIN := $(patsubst %.cpp, %, $(wildcard *.cpp))

all: $(OBJ) $(BIN)

rebuild: clean all

$(ODIR)/%.o: $(SDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

$(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(IDIR)

%: $(DEP) $(ODIR)/%.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	@rm -rf $(ODIR) *.o $(BIN)
