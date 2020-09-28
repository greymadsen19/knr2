CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -pedantic-errors -g
LDFLAGS = 

SRCDIR = src
OBJDIR = obj
BLDDIR = bin

TARGET =  noungetch

SRC := $(shell find $(SRCDIR) -name '*.c')
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

$(BLDDIR)/$(TARGET): $(OBJ)
	@mkdir -pv $(BLDDIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -pv $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rv $(OBJDIR)
	
