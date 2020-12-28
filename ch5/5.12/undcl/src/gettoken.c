#include "undcl.h"

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int prevtok = FALSE;

int gettoken(void) {
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  if (prevtok == TRUE) {
    prevtok = FALSE;

    return tokentype;
  }

  while ((c = getch()) == ' ' || c == '\t')
    ;

  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    }
    else {
      ungetch(c);
      return tokentype = '(';
    }
  }
  else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']';)
      ;
  
    *p = '\0';
    return tokentype = BRACKETS;
  }
  else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());)
      *p++ = c;

    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  }
  else
    return tokentype = c;
}

int nexttok(void) {
  int type;

  type = gettoken();

  prevtok = TRUE;

  return type;
}

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  }
  else
    buf[bufp++] = c;
}
