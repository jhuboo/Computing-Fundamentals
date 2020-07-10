/* all variables must be declaraed before use */
int lower, upper, step;
char c, line[1000];

/* To make it more explicit with comments for each declaration */
/* this can be rewritten as: */
int lower;
int upper;
int step;
char c;
char line[1000];

/* a variable can also be initialized in its declaration */
char esc = '\\';
int i = 0;
int limit = MAXLINE+1;
float eps = 1.0e-5;

/* the qualifier const is applied to the declaration of any variable
    to specify that its value will not be changed */
const double e = 2.71828182845905;
const char msg[] = "warning: ";

/* the 'const' declaration can also be used with array arguments to indicate
    that the function does not change that array */
int strlen(const char[]);
