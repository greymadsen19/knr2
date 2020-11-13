#include <stdio.h>
#include "expr.h"

#define MAXVAL 100

int sp = 0;

double val[MAXVAL];

void push(double n) {
  if (sp < MAXVAL) {
    val[sp++] = n;
  }
  else
    printf("error: stack full. can't push %f\n", n);
}

double pop(void) {
  if (sp > 0) {
    return val[--sp];
  }
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}
