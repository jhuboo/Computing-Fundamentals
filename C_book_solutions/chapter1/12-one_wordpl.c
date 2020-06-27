#include <stdio.h>

#define IN  0   /* being inside a word */
#define OUT 1   /* being outside a word */ 

/* prints inputs one word per line */
main ()
{
    int c;
    int inspace;

    inspace = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (inspace == IN) {
                inspace = OUT;
                putchar('\n');
            }
        /* else don't print anything */
        } else {
            inspace = IN;
            putchar(c);
        }
    }
}
