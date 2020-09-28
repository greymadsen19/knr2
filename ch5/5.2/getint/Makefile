CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -g
LDFLAGS =

SRCDIR = src
OBJDIR = obj
BLDDIR = bin

TARGET = getint

SRC := $(shell find $(SRCDIR) -name '*.c')
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

$(BLDDIR)/$(TARGET): $(OBJ)
	@mkdir -pv $(BLDDIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -pv $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rv $(OBJDIR)
