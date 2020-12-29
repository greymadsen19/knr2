#include "dcl.h"
#include <stdlib.h>

int isequal(const void *, const void *);

void dcl(void) {
  int ns;;

  for(ns = 0; gettoken() == '*';)
    ns++;
  dirdcl();
  while (ns-- > 0)
    strcat(out, " pointer to");
}

void dirdcl(void) {
  int type;
  void paramdcl(void);

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')') {
      printf("error: missing )\n");
      prevtok = TRUE;
    }
  }
  else if (tokentype == NAME)
    strcpy(name, token);
  else {
    if (paramtype)
      prevtok = TRUE;
    else {
      printf("error expected name or (dcl)\n");
      prevtok = TRUE;
    }
  }

  while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
    if (type == PARENS)
      strcat(out, " function returning");
    else if (type == '(') {
      strcat(out, " function expecting");
      paramdcl();
      strcat(out, "and returning");
    }
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}

void paramdcl(void) {
  char temp[MAXTOKEN];

  do {
    temp[0] = '\0';
    gettoken();
    strcat(out, " ");
    dclspc();
    paramtype = 1;
    dcl();
    paramtype = 0;
    if (tokentype == ',')
      strcat(temp, ", ");
    strcat(out, " ");
    strcat(out, temp);
  } while (tokentype == ',');

  if (tokentype != ')') {
    printf("missing ) in parameter declaration\n");
    prevtok = TRUE;
  }
}

void dclspc(void) {
  int typespc(void), typequal(void);
  int count;

  for (count = 0; tokentype == NAME && (typespc() || typequal()); ++count) {
    if (count)
      strcat(out, " ");

    strcat(out, token);
    gettoken();
  }

  prevtok = TRUE;
}

int typespc(void) {
  char *spec[] = {
    "char",
    "double",
    "float",
    "int",
    "long",
    "signed",
    "unsigned",
    "void"
  };

  if (!bsearch(&token, spec, sizeof(spec) / sizeof(spec[0]), sizeof(char *), isequal))
    return 0;

  return 1;
}

int typequal(void) {
  char *qual[] = {
    "const",
    "volatile"
  };

  if (!bsearch(&token, qual, sizeof(qual) / sizeof(qual[0]), sizeof(char *), isequal))
    return 0;

  return 1;
}

int isequal(const void *s, const void *t) {
  return strcmp((char *) s, *(char **) t);
}
