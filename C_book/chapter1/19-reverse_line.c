#include <stdio.h>

#define MAXLINE 1024

int mygetline(char line[], int maxline);
int revstringf(char line[], char revline[]);

/* reverses string using revstringf function */
main()
{
    char line[MAXLINE];
    char revline[MAXLINE];

    while ((mygetline(line, MAXLINE)) > 0) {
        revstringf(line, revline);
        printf("%s", revline);
    }

    return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    
    return i;
}

/* revstringf: reverses string s */
int revstringf(char s[], char revline[])
{
    int i, ii;

    i = 0;
    
    while (s[i] != '\n')    /* find number of last char in a string */
        ++i;

    ii = 0;

    /* last char of s place as first char of revline and so on */
    for (i = i - 1; i >= 0; --i) {
        revline[ii] = s[i];
        ++ii;
    }

    revline[ii] = '\n';
    revline[++ii] = '\0';
    
    return 0;
}
