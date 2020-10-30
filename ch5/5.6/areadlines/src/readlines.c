#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

size_t mgetline(char *, size_t);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
  int nlines, len;
  char line[MAXLEN];
  char *allocp;

  nlines = 0;
  while((len = mgetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (allocp = alloc(len)) == NULL)
      return -1;
    else {
      line[len -1] = '\0';
      strcpy(allocp, line);
      lineptr[nlines++] = allocp;
    }
  }

  
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

size_t mgetline(char *line, size_t lim) {
  int c;
  char *linep = line;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *linep++ = c;

  if (c == '\n')
    *linep++ = c;

  *linep = '\0';

  return linep - line;
}
