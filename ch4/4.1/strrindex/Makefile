#Makefile

CC = gcc 
CFLAGS = -std=c99 -Wall -Wextra -pedantic -pedantic-errors -g

TARGET = strrindex

OBJDIR = obj
SRCDIR = src
BLDDIR = bin

SRC = $(shell find $(SRCDIR) -name '*.c')
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

$(BLDDIR)/$(TARGET): $(OBJ)
	@mkdir -pv $(BLDDIR)
	$(CC) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -pv $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rv $(OBJDIR)
