#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that number was found */
#define IDENTIFIER 1    /* associated state */
#define ENDSTRING 2
#define MAX_ID_LEN 32
#define MAXVARS 30

struct varType{
    char name[MAX_ID_LEN];
    double val;
};

int getop(char []);
void push(double);
double pop(void);
void showTop(void);
void duplicate(void);
void swapItems(void);
void clearStack(struct varType var[]);
void dealWithName(char s[], struct varType var[]);
void dealWithVar(char s[], struct varType var[]);

int pos = 0;
struct varType last;

/* reverse Polish calculator */
main()
{
    int type;
    double op2;
    char s[MAXOP];
    struct varType var[MAXVARS];

    clearStack(var);

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case IDENTIFIER:
            dealWithName(s, var);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2)
                push(fmod(pop(), op2));
            else
                printf("\nError: division by zero!");
                break;
        case '?':
            showTop();
            break;
        case '#':
            duplicate();
            break;
        case '~':
            swapItems();
            break;
        case '!':
            clearStack(var);
        case '\n':
            printf("\t%.8g\n", pop());
        case ENDSTRING:
            break;
        case '=':
            pop();
            var[pos].val = pop();
            last.val = var[pos].val;
            push(last.val);
            break;
        case '<':
            printf("The last variable used was: %s (value == %g)\n",
                                                    last.name, last.val);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100      /* max depth of val stack */

int sp = 0;             /* next free stack positon */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* showTop: show top items without popping them */
void showTop(void)
{
    if (sp > 0)
        printf("Top of stack contains: %8g\n", val[sp-1]);
    else
        printf("The stack is empty...\n");
}

/* duplicate:  duplicates the element and push it into a tmp variable */
void duplicate(void)
{
    double temp = pop();

    push(temp);
    push(temp);
}

/* swapItems:  swaps items */
void swapItems(void)
{
    double item1 = pop();
    double item2 = pop();

    push(item1);
    push(item2);
}

/* clearStack:  clears the stack */
void clearStack(struct varType var[])
{
    int i;
    
    /* clears the main stack by setting pointer to the bottom */
    sp = 0;

    /* clear the variables by setting the inital element of each name to 
        the terminating character */
    for (i = 0; i < MAXVARS; ++i) {
        var[i].name[0] = '\0';
        var[i].val = 0.0;
    }
}

/* dealWithName:  deal with a string/name - sin, cos, exp, pow */
void dealWithName(char s[], struct varType var[])
{
    double op2;

    if (0 == strcmp(s, "sin"))
        push(sin(pop()));
    else if (0 == strcmp(s, "cos"))
        push(cos(pop()));
    else if (0 == strcmp(s, "exp"))
        push(exp(pop()));
    else if (!strcmp(s, "pow"))
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
       dealWithVar(s, var);
}

/* dealWithVar:  since our identifier is not one of the supported math
    funtions, we have to regard it as an identifier */
void dealWithVar(char s[], struct varType var[])
{
    int i = 0;

    while (var[i].name[0] != '\0' && i < MAXVARS-1) {
        if (!strcmp(s, var[i].name)) {
            strcpy(last.name, s);
            last.val = var[i].val;
            push(var[i].val);
            pos = i;
            return;
        }
        i++;
    }
    
    /* variable name no found, so add it */
    strcpy(var[i].name, s);
    /* and save it to the last variable */
    strcpy(last.name, s);
    push(var[i].val);
    pos = i;
}


int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    static char buf = EOF;

    if (buf == EOF || buf == ' ' || buf == '\t') {
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
        s[1] = '\0';
    }
    else
        c = buf;

    if (!isdigit(c) && c != '.')
        return c;       /* not a number */

    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        buf = c;

    return NUMBER;
}

#define BUFSIZE 100

int buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void)         /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ungets:  pushes back an entire string onto the input */
void ungets(const char *s)
{
    size_t i = strlen(s);

    while (i > 0)
        ungetch(s[--i]);
}
