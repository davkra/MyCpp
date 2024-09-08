CC := g++
MAIN := main test
FILENAMES := print

SOURCEDIR := ./
OBJDIR := ./obj
INCLUDEDIR := ./

CFLAGS := -Wall -g -std=c++11 -I$(INCLUDEDIR)
MKDIR := mkdir -p

_OBJ := $(FILENAMES:=.o)
OBJ := $(patsubst %,$(OBJDIR)/%,$(_OBJ))

_BIN := $(MAIN:=.o)
BIN := $(patsubst %,$(OBJDIR)/%,$(_BIN))

all: $(OBJDIR) $(OBJ) $(BIN) $(MAIN)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

%: $(OBJDIR) $(OBJDIR)/%.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(filter-out $<,$^)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

.PHONY: clean

clean:
	rm -rf $(MAIN) $(OBJDIR)
	git clean -fdx
