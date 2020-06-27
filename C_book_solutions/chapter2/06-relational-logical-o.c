/* The relational operators are >, >=, <, <=    */
/* They all have the same precedence */
/* Just below them in precedence are the equality operators: ==, !=     */

/* Relational operators have lower precedence than arithmetic opertors,
    so an expression like:
    i < lim - 1
    i < (lim - 1)   */

/* The logical operators && and || are evalutated left to right, and evaluation
    stops as soon as the truth or falsehood of the result is known. */

for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;

/* The precedence of && is higher than that of ||, and
    both are lower than relational and equality operators
    which is why the above expression needs no extra parentheses. */

/* Write the 'for' loop above without && or || */
#include <stdio.h>

#define MAX_STRING_LENGTH 100

int main(void)
{
    int i = 0, lim = MAX_STRING_LENGTH, c;
    char s[MAX_STRING_LENGTH];

    while (i < (lim - 1)) {
        c = getchar();

        if (c == EOF)
            break;
        else if (c == '\n')
            break;

        s[i++] = c;
    }

    s[i] = '\0';    /* terminate the string */

    return 0;
}
