#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *[], int);
void writelines(char *[], int, int);

enum states { NUMERIC = 1, REVERSE = 2, FOLD = 4 };

void qsort(void *[], int, int, int (*comp)(void *, void *));

int numcmp(const char *, const char *);
int fold(const char *, const char *);

int main(int argc, char *argv[]) {
  int nlines;
  int c;
  int option = 0;
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
      default:
        printf("%s: invalid option -- '%c'\n", prog, c);
        printf("usage: %s [-nrf]\n", prog);
        return -1;
        break;
      }
  
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **) lineptr, 0, nlines - 1,
      (int (*)(void *, void *))(option & NUMERIC ? numcmp : 
              option & FOLD ? fold : strcmp));
    writelines(lineptr, nlines, option & REVERSE);
    return 0;
  }
  else { 
    printf("input too big to sort\n");
    return -1;
  }
}
