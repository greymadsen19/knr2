void my_strcat(char *s, char *t) {
	while (*++s);
	while ((*s++ = *t++));
}
