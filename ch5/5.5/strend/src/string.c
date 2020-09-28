int mstrlen(char *s) {
	int i;

	for (i = 0; *s++ != '\0'; i++);

	return i;
}

int strend(char *s, char *t) {
	int sl, tl;

	sl = mstrlen(s);
	tl = mstrlen(t);
	
	s += sl - tl;
	
	while(*s && *s++ == *t++);

	return !*s;
}

