#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { FALSE, TRUE };

void dcl(void);
void dirdcl(void);
void dclspc(void);

int gettoken(void);
int tokentype;
int prevtok;
int paramtype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
