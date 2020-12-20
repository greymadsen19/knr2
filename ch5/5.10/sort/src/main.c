#include <stdio.h>
#include <string.h>
#include "sort.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *[], int);
void writelines(char *[], int, int);

void qsort(void *[], int, int, int (*comp)(void *, void *));

int main(int argc, char *argv[]) {
  int nlines;
  int c;
  extern int option;
  option = 0;

  char *prog = *argv;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c) {
      case 'n':
        option |= NUMERIC;
        break;
      case 'r':
        option |= REVERSE;
        break;
      case 'f':
        option |= FOLD;
        break;
      case 'd':
        option |= DIR;
        break;
      default:
        printf("%s: invalid option -- '%c'\n", prog, c);
        printf("usage: %s [-dfrn]\n", prog);
        return -1;
        break;
      }
  
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **) lineptr, 0, nlines - 1,
      (int (*)(void *, void *))(option & NUMERIC ? numcmp : 
              (option & FOLD) || (option & DIR) ? alnumcmp : strcmp));
    writelines(lineptr, nlines, option & REVERSE);
    return 0;
  }
  else { 
    printf("input too big to sort\n");
    return -1;
  }
}
