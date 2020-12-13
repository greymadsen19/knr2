#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int mgetline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = mgetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }

  return nlines;
}

void writelines(char *lineptr[], int nlines, int reverse) {
  if (reverse)
    while (nlines-- > 0)
      printf("%s\n", lineptr[nlines]);
  else
    while (nlines-- > 0)
      printf("%s\n", *lineptr++);
}

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
