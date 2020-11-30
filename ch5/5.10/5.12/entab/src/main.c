#include <stdio.h>

#define MAXLEN 1000

int main(int argc, char *argv[]) {
  char line[MAXLEN];
  char entabbed[MAXLEN];

  int n = 4, m = 1;

  int mgetline(char *, int);
  int readargs(int, char **, int *, int *);
  void entab(char *, char *, int *, int *);

  if (readargs(argc, argv, &m, &n) < 0)
    return -1;

  while (mgetline(line, MAXLEN) > 0) {
    entab(entabbed, line, &m, &n);
    printf("%s", entabbed);
  }
  
  return 0;
}

