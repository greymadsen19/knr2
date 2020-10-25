#include <string.h>

int mstrcmp(char *s, char *t);
void swap(char *[], int, int);

void qsort(char *lineptr[], int left, int right) {
  int i, last;

  if (left >= right)
    return;

  swap(lineptr, left, (left + right) / 2);

  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(lineptr[i], lineptr[left]) < 0)
      swap(lineptr, ++last, i);

  swap(lineptr, left, last);
  qsort(lineptr, left, last - 1);
  qsort(lineptr, last + 1, right);
}

void swap(char *lineptr[], int i, int j) {
  char *temp;

  temp = lineptr[i];
  lineptr[i] = lineptr[j];
  lineptr[j] = temp;
}

