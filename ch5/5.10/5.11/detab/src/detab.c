#include <stdlib.h>

#define N 4

int settabstop(int, int *, int);
int settabs(int, char **, int *);

void detab(char *to, char *from, int *tabs, int size) {
  int ns, i, j;

  for (i = 0, j = 0; from[i] != '\0'; ++i) {
    if (from[i] == '\t') {
      ns = settabstop(j, tabs, size);
      while (ns-- > 0)
        to[j++] = ' ';
    }
    else
      to[j++] = from[i];
  }

  to[j] = '\0';
}

int settabstop(int position, int *tabs, int size) {
  if (!size)
    return N - (position % N);

  while (size != 0 && position >= *tabs) {
    ++tabs;
    --size;
  }

  return *tabs - position;
}

int settabs(int argc, char **argv, int *tabs) {
  int i;

  for (i = 0; --argc > 0; ++i) {
    if (!(tabs[i] = atoi(*++argv)) || tabs[i] < 0)
      return -1;
  }

  return i;
}
