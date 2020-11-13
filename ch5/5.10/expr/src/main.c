#include <stdio.h>
#include <stdlib.h>
#include "expr.h"


int main(int argc, char *argv[]) {
  int type;
  int num;
  double op2;

  if (argc < 4) {
    printf("usage: %s <expr>...\n", argv[0]);
    return -1;
  }
  
  while (--argc > 0) {
    ++argv;
    if ((num = atof(*argv)))
      type = NUMBER;
    else
      type = **argv;

    switch(type) {
    case NUMBER:
      push(num);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 == 0.0) {
	printf("error: division by zero\n");
	argc = 1;
      }
      else {
	push(pop() / op2);
      }
      break;
    case '%':
      op2 = pop();
      if (op2 == 0.0) {
	printf("error: division by zero\n");
	argc = 1;
      }
      else {
	push((int)pop() % (int)op2);
      }
      break;
    default:
      printf("error: unknown command %s\n", *argv);
      argc = 1;
      break;
    }
  }

  printf("%.8g\n", pop());
  return 0;
}
