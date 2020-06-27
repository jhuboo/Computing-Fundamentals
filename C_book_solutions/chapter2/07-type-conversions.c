/* when an operator has operands of different types, they are converted
    to a common type according to a small number of rules.

    In general, the only automatic conversions are those that conver a 
    "narrower" operand into a "wider" one without losing information,
    such as converting an integer to a float in: f + i

    Expressions that don't make sense, like using a float as a subscript
    are disallowed.

    Expressions that might lose information like assigning a long integer type
    to a short, or a floating-point type to an integer, may draw a warning,
    but they are not illegal.       */

/* A char is just a small integer, so "chars" may be freely used in
    arithmetic expressions.

    This is exemplified by the function "atoi" which converts a string
    of digits into its numeric equivalents.         */

/* atoi: convert s to integer */
int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');      /* s[i] - '0' gives the numeric
                                           value of the character stored
                                           in s[i], because the values
                                           '0', '1', etc, form a contiguous
                                           increasing sequence */

    return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';       /* this works because corresponding
                                       upper case and lower case letters
                                       are a fixed distance apart as numeric
                                       values and each alphabet is contiguous */
    else
        return c;
}

/* The standard header <ctype.h> defines a family of functions that 
    provide tests and conversions that are independent of character set.

    ie, c >= '0' && c <= '9' can be replaced by: isdigit(c)      */

/* There is one subtle point about the conversion of charactes to integers.
    The language does not specify whether variables of type char are signed
    or unsigned.    */

/* The definition of C guarantees that any character in the machine's standard
    printing character set will never be negative, so these characters will
    always be positive quantities in expressions. But arbitrary bit patterns
    may appear to be negative on some machines, yet positive on others. For
    portability, specify "signed" or "unsigned" if non-character data is to 
    be stored in "char" variables.  */

/* Relational expressions have values true: 1, false: 0     */
/* However functions like "isdigit" may return any non-zero value for true */

/* Implicit arithmetic conversions work much as expected,
    the "lower" type is promoted to the "higher" type before
    the operation proceeds.

    If either operand is "long double", convert the other to "long double"
    If "double" -> "double"
    If "float" -> "float"
    If "char" && "short" -> "int"
    If "long" -> "long"             */

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
    next = seed;
}


/* Exercise 2-3: Write a function htoi(s), which converts a string
    of hexadecimal digits (including an optional 0x of 0X) into its equivalent
    integer value. The allowable digits are 0 through 9, a through f, A - F. */

#include <stdio.h>
#include <ctype.h>

unsigned long htoi(const char s[]);

int main(void)
{
    printf("%ld\n", htoi("0xFA9C"));
    printf("%ld\n", htoi("0xFFFF"));
    printf("%ld\n", htoi("0x1111"));
    printf("%ld\n", htoi("0xBCDA"));
    
    return 0;
}

unsigned long htoi(const char s[])
{
    unsigned long n = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int c = tolower(s[i]);

        if (c == '0' && tolower(s[i+1]) == 'x')
            i++;
        else if (c >= '0' && c <= '9')
            n = 16 * n + (c - '0');
        else if (c >= 'a' && c <= 'f')
            n = 16 * n + (c - 'a' + 10);
    }

    return n;
}
