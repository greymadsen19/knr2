void reverse(char s[], int i, int j) {
	int c;

	if (i < j) {
		reverse(s, i + 1, j - 1);
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}	

}
