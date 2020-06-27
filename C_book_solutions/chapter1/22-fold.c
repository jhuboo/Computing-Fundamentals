#include <stdio.h>

#define MAXLINE 1000        /* max input line size */

char line[MAXLINE];         /* current input line */

int getlines(void);          /* take from the KnR book */

/* fold long input lines into two or more shorter lines
    after the last non-blank character that occurs
    before the n-th column of input */
main()
{
    int t, len;
    int location, spaceholder;
    const int FOLDLENGTH = 70;      /* max length of line */

    while((len = getlines()) > 0) {
        if (len < FOLDLENGTH)
            ;
        else {
            t = 0;
            location = 0;
            
            while (t < len) {
                if (line[t] == ' ')
                    spaceholder = t;
                
                if (location == FOLDLENGTH) {
                    line[spaceholder] = '\n';
                    location = 0;
                }
                location++;
                t++;
            }
        }
        printf("%s", line);
    }

    return 0;
}

/* getlines: specialized version */
int getlines(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != 'n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    
    line[i] = '\0';

    return i;
}
