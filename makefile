CC := g++
CFLAGS := -Wall -g -std=c++11 -I./

MAIN := main test
DEPN := print

OBJ := $(patsubst %, %.o, $(MAIN) $(DEPN))

all: $(OBJ) $(MAIN)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

%: %.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $< $(filter-out $(patsubst %, %.o, $(MAIN)), $^)

.PHONY: clean

clean:
	rm -rfv $(MAIN) $(OBJ)
