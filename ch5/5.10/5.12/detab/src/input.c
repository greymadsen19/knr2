#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mgetline(char *line, int lim) {
  int c;

  char *len = line;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *line++ = c;

  if (c == '\n')
    *line++ = c;

  *line = '\0';

  return strlen(len);
}

int readargs(int argc, char **argv, int *m, int *n) {
  int poserr = 0;

  char *args = *argv;

  if (argc == 1)
    return 0;

  while (--argc > 0) {
    if (strcmp(*++argv, "-m") == 0) {
      if ((*m = atoi(*++argv)) < 1) {
	poserr = 1;
	break;
      }
      --argc;
    }
    else if (strcmp(*argv, "+n") == 0) {
      if ((*n = atoi(*++argv)) < 1) {
	poserr = 1;
	break;
      }
      --argc;
    }
    else {
      printf("usage: %s [-m pos] [+n pos]\n", args);
      return -1;
    }
  }

  if (poserr) {
    printf("error: %s invalid position %s\n", args, *argv);
    return -1;
  }
  
  return 1;
}
