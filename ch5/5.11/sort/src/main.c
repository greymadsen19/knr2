#include "sort.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *[], int);
void writelines(char *[], int, int);

void mqsort(void *[], int, int, int (*comp)(void *, void *));

int main(int argc, char *argv[]) {
  int nlines;
  int c;
  extern int option;
  extern int pos1;
  extern int pos2;
  pos1 = pos2 = option = 0;

  char *prog = *argv;

  while (--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+'))
    if (c == '-' && !isdigit(*(argv[0] + 1)))
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
          printf("usage: %s [-dfrn] [+pos1] [-pos2]\n", prog);
          return -1;
          break;
        }
    else if (c == '-')
      pos2 = atoi(argv[0] + 1);
    else if ((pos1 = atoi(argv[0] + 1)) < 0) {
      printf("usage: %s [-dfrn] [+pos1] [-pos2]\n", prog);
      return -1;
    }

  if (argc || pos1 > pos2) {
    printf("usage: %s [-dfrn] [+pos1] [-pos2]\n", prog);
    return -1;
  }
  
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    mqsort((void **) lineptr, 0, nlines - 1,
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
