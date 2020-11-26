#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define TABSTOP 100 

int main(int argc, char *argv[]) {
  char line[MAXLEN];
  char entabbed[MAXLEN];
  int tabs[TABSTOP];
  int size;

  int mgetline(char *, int);
  int settabs(int, char **, int *);
  void entab(char *, char *, int *, int);

  if ((size = settabs(argc, argv, tabs)) < 0)
    return -1;
  while (mgetline(line, MAXLEN) > 0) {
    entab(entabbed, line, tabs, size);
    printf("%s", entabbed);
  }

  return 0;
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
