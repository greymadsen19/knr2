#define NUMBER 0
#define NAME 1

void push(double);
double pop(int);
int getop(char []);
int getch(void);
void ungetch(int);
int math(char s[]);
void prompt(void);

enum State {
	PP = 0,
	KE = 1,
	SW = 2,
	CL = 3
};
