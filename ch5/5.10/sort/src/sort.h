#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int option;
int pos1;
int pos2;
enum states { NUMERIC = 1, REVERSE = 2, FOLD = 4, DIR = 8 };

int numcmp(const char *, const char *);
int alnumcmp(const char *, const char *);
