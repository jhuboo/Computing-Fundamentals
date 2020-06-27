#include <stdio.h>

/* This program copies its input to its output, replacing
    each string of one of more blanks by a single blank. */

main()
{
    int c;
    int inspace;
    
    inspace = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (inspace == 0)
            {
                inspace = 1;
                putchar(c);
            }
        }

        /* We haven't met 'else' yet, so we have to be a little clumsy */
        if (c != ' ')
        {
            inspace = 0;
            putchar(c);
        }
    }

}
