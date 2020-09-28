#include <ctype.h>

/* convert string to double handling
 * special case such as 2.36e+4
 */
double atof(char s[]) {
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '-' || s[i] == '+')
	       i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (tolower(s[i++]) == 'e') {
		int exp_sign;
		int exp;
		double exp_power;

		exp_sign = (s[i] == '-') ? -1 : 1;

		if (s[i] == '-' || s[i] == '+')
			i++;

		exp = 0;
		if (isdigit(s[i + 1])) {
			exp += 10 * (s[i] - '0');
			exp += s[i] - '0';
		}
		else
			exp += s[i] - '0';
		
		for (i = 0, exp_power = 1.0; i < exp; i++)
			exp_power *= 10;

		if (exp_sign == -1) return ((sign * val / power) / (exp_power));
		else return ((sign * val / power) * (exp_power));

	}
	else return sign * val / power;
}
