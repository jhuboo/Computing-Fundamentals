#include <stdio.h>

/* This program prompts for input, then captures a char
    from the keyboard. If EOF is signalled (typically through
    Ctrl-D, or Ctrl-Z)
    the program prints 0. Otherwise, it prints 1.

    If your input is buffered (and it probably is), then
    you will need to press the ENTER key before the program
    will respond.   */
main()
{
    printf("Press a key. ENTER would be nice :-)\n\n");
    printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);
}
