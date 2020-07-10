#include <stdio.h>

/* This program copies its input to its output, replacing each
    tab by \t, each backspace by \b, each backslash by \\  */
main()
{
    int c, d;
    
    while ((c = getchar()) != EOF) {
        d = 0;

        if (c == '\t') {
            putchar('\\');
            putchar('t');
            d = 1;
        }
        
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
            d = 1;
        }
        
        if (c == '\b') {
            putchar('\\');
            putchar('b');
            d = 1;
        }

        if (d == 0) {
            putchar(c);
        }
    }
}
