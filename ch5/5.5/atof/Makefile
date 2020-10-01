CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wshadow -pedantic -g
LDFLAGS =

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRC := $(shell find $(SRCDIR) -name '*.c')
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

TARGET = atof

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -pv $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR)/$(TARGET): $(OBJ)
	@mkdir -pv $(BINDIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

.PHONY: clean

clean:
	@rm -rv $(OBJDIR)
