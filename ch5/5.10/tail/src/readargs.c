#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readargs(int count, char **args, int *n) {
  char *argp = *args;
  char *endp;

  while (--count > 0) {
    if (!strcmp(*++args, "-n")) {
      endp = NULL;
      if (!(*n = strtol(*++args, &endp, 10)) || *endp) {
        printf("error: %s invalid line %s\n", argp, *args);
        return 0;
      }
      *n = abs(*n);
      --count;
    }
    else {
      printf("usage: %s [-n line]\n", argp);
      return 1;
    }
  }

  return 1;
}
