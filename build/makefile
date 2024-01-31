CC := g++
CFLAGS := -std=c++11 -Wall -g -ggdb
SRCDIR := ../src
INCDIR := ../include
BUILDDIR := build
TARGET := $(BUILDDIR)/CircularBufferExample

SRCEXT := cpp
SOURCES := $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
INC := -I$(INCDIR)

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) $(INC) $^ -o $@
	@echo "Linking complete!"

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiled $< successfully"

clean:
	@rm -rf $(BUILDDIR)
	@echo "Cleanup complete!"

.PHONY: clean

