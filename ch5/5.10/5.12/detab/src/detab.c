void detab (char *to, char *from, int *m, int *n) {
  int ns, i, j;

  for (i = 0, j = 0; from[i]; ++i) {
    if ((j + 1) >= *m && from[i] == '\t') {
      ns = *n - (j % *n);

      while (ns-- > 0)
	to[j++] = ' ';
    }
    else
      to[j++] = from[i];
  }

  to[j] = '\0';
}
