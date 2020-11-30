#include <stdio.h>

#define MAXLEN 1000

int main(int argc, char *argv[]) {
  char line[MAXLEN];
  char detabbed[MAXLEN];

  int m = 1, n = 4;

  int mgetline(char *, int);
  int readargs(int, char **, int *, int *);
  void detab(char *, char *, int *, int *);

  if (readargs(argc, argv, &m, &n) < 0)
    return 1;

  while (mgetline(line, MAXLEN) > 0) {
    detab(detabbed, line, &m, &n);
    printf("%s", detabbed);
  }

  return 0;
}
