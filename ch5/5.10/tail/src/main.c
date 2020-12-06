#include <stdio.h>

#define MAXLINES 5000

int readlines(char *[], int);
void writelines(char *[], int);
int readargs(int, char **, int *);

int main(int argc, char *argv[]) {
  int nlines;
  int n = 10;

  char *lineptr[MAXLINES];

  if (!readargs(argc, argv, &n))
    return 1;
  
  if ((nlines = readlines(lineptr, MAXLINES)) < 0) {
    printf("error: input too big\n");
    return 1;
  }

  if (n > nlines)
    n = nlines;

  writelines(lineptr + nlines - n, n);

  return 0;
}
