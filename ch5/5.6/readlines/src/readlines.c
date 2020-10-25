#include <stdio.h>
#include <string.h>

#define MAXLEN 100

size_t mgetline(char *, size_t);

int readlines(char *lineptr[], char *allocp, int maxlines) {
  int nlines, len;
  char line[MAXLEN];

  nlines = 0;
  while((len = mgetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || allocp == NULL)
      return -1;
    else {
      line[len -1] = '\0';
      strcpy(allocp, line);
      lineptr[nlines++] = allocp;
      allocp += len;
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
