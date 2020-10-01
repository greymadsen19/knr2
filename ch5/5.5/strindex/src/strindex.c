int mstrindex (char *s, char *t) {
	int pos;
	char *j, *k;

	for (pos = 0; *s; s++, pos++) {
		for (j = s, k = t; *k && (*j == *k); j++, k++);
		if (k > t && *k == '\0') return pos;
	}

	return -1;
}
