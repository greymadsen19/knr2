#include <stdlib.h>
#include <ctype.h>
#include "sort.h"

int numcmp(const char *s1, const char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

int alnumcmp(const char *s, const char *t) {
  int dir = option & DIR;
  int fold = option & FOLD;

  if (dir) {
    while (isalnum(*s) || isblank(*s)) {
      ++s;
    }

    while (isalnum(*s) || isblank(*t)) {
      ++t;
    }
  }

  if (fold) {
    for (; toupper(*s) == toupper(*t); s++, t++)
      if (*s == '\0')
        return 0;
  }

  return fold ? toupper(*s) - toupper(*t) : *s - *t;
}
