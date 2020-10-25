#include <stdio.h>

#define MAXLINES 5000
#define MAXSIZE 10000

int readlines(char *[], char *, int);
void writelines(char *[], int);

void qsort(char *[], int, int);

int main(void) {
  char *lineptr[MAXLINES];
  char alloc[MAXSIZE];

  int nlines;

  if ((nlines = readlines(lineptr, alloc, MAXLINES)) < 0) {
    printf("error: input too big to sort\n");
    return 1;
  }

  qsort(lineptr, 0, nlines - 1);
  writelines(lineptr, nlines);
  return 0;

}
