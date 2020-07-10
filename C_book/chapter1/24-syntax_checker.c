#include <stdio.h>

#define MAXLINE 1000        /* max input line size */

char line[MAXLINE];         /* current input line */

int getlines(void);         /* taken from KnR book */

/* check for general syntax */
main()
{
    int len = 0;
    int t = 0;
    int brace = 0, curly_brace = 0, bracket = 0, parenthesis = 0;
    int s_quote = 1, d_quote = 1;

    while ((len = getlines()) > 0) {
        t = 0;
        while ( t < len) {
            /* check for braces */
            if (line[t] == '[')
                brace++;
            if (line[t] == ']')
                brace--;

            /* check for curly braces */
            if (line[t] == '{')
                curly_brace++;
            if (line[t] == '}')
                curly_brace--;

            /* check for parenthesis */
            if (line[t] == '(')
                parenthesis++;
            if (line[t] == ')')
                parenthesis--;

            /* check for others */
            if (line[t] == '\'')
                s_quote *= -1;
            if (line[t] == '"')
                d_quote *= -1;
            
            t++;
        }
    }

    if (d_quote != 1)
        printf("Mismatching double quote mark\n");
    if (s_quote != 1)
        printf("Mismatching single quote mark\n");
    if (parenthesis != 0)
        printf("Mismatching parenthesis\n");
    if (brace != 0)
        printf("Mismatching brace mark\n");
    if (curly_brace != 0)
        printf("Mismatching curly_brace mark\n");
    if (bracket != 0)
        printf("Mismatching bracket mark\n");

    if (bracket == 0 && brace == 0 && curly_brace == 0 && parenthesis == 0
        && s_quote == 1 && d_quote == 1)
            printf("Syntax seems correct!\n");

    return 0;
}

/* getlines: specialized version */
int getlines(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}
