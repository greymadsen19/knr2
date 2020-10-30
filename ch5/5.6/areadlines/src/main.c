#include <stdio.h>

#define MAXLINES 5000

int readlines(char *[], int);
void writelines(char *[], int);

void qsort(char *[], int, int);

int main(void) {
  char *lineptr[MAXLINES];

  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) < 0) {
    printf("error: input too big to sort\n");
    return 1;
  }

  qsort(lineptr, 0, nlines - 1);
  writelines(lineptr, nlines);
  return 0;

}
