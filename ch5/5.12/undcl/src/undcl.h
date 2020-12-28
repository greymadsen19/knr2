#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { FALSE, TRUE };

int gettoken(void);
int nexttok(void);
int tokentype;
extern int prevtok;
char token[MAXTOKEN];
char out[1000];
