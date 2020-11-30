void entab(char *to, char *from, int *m, int *n) {
  int nt, ns, i, j;

  for (i = 0, j = 0; from[i] != '\0'; ++i) {
    if (from[i] == ' ') {
      for (nt = 0, ns = 0; from[i] == ' '; ++i) {
	if (i + 1 >= *m && (i + 1) % *n == 0) {
	  ++nt;
	  ns = 0;
	}
	else
	  ++ns;
      }
      --i;

      while (nt-- > 0)
	to[j++] = '\t';

      while (ns-- > 0)
	to[j++] = ' ';
    }
    else
      to[j++] = from[i];
  }

  to[j] = '\0';
}
