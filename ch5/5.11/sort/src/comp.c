#include "sort.h"

#define MAXLEN 1000

int numcmp(const char *s1, const char *s2) {
  double v1, v2;
  void substr(const char *, char *);
  char str[MAXLEN];

  substr(s1, str);
  v1 = atof(str);
  substr(s2, str);
  v2 = atof(str);

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
  int endpos;

  extern int pos1;
  extern int pos2;
  
  if (pos2 > 0)
    endpos = pos2;
  else if ((endpos = strlen(s)) > (int) strlen(t))
    endpos = strlen(t);

  s += pos1;
  t += pos1;

  do {
    if (dir) {
      while (s < s + pos2 && !isalnum(*s) && !isblank(*s)) {
        ++s;
      }

      while (t < t + pos2 && !isalnum(*t) && !isblank(*t)) {
        ++t;
      }
    }

    if (fold) {
      if (s < s + pos2 && t < t + pos2) {
        ++s;
        ++t;
        if (toupper(*s) == toupper(*t) && *s == '\0')
         return 0;
      }
    }
  } while (*s == *t && s < s + pos2 && t < t + pos2);

  return fold ? toupper(*s) - toupper(*t) : *s - *t;
}

void substr(const char *s, char *str) {
  int len;
  int i, j;

  extern int pos1;
  extern int pos2;

  len = strlen(s);

  if (pos2 > 0 && len > pos2)
    len = pos2;
  else if (pos2 > 0 && len < pos2) {
    printf("substr: string is too short\n");
    exit(1);
  }

  for (j = 0, i = pos1; i < len; i++, j++)
    str[j] = s[i];

  str[j] = '\0';
}
