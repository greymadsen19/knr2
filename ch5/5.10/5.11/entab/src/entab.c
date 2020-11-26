#include <stdlib.h>

#define N 4

int settabstop(int, int *, int);
int settabs(int, char **, int *);

void entab(char *to, char *from, int *tabs, int size) {
  int ns, nt, tabstop, i, j;

  ns = nt = tabstop = i = j = 0;

  for (i = 0, j = 0; from[i] != '\0'; ++i) {
    if (from[i] == ' ') {
      for (nt = 0, ns = 0; from[i] == ' '; ++i) {
        tabstop = settabstop(i, tabs, size);
        if ((i + 1) % tabstop == 0) {
          ++nt;
          ns = 0;
        }
        else
          ++ns;
      }
      --i;

      while (nt-- > 0)
        to[j++] = '\t';
     
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
    return N;

  while (position >= *tabs) {
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

