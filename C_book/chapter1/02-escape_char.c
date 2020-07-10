#include <stdio.h>

/* experiment with escape characters such as
    \n, \t, \b, \", \\.                 */
main()
{
    printf("Audible or visual alert. \a\n");
    printf("Form feed. \f\n");
    printf("This escape, \r, moves the active position to the initial position of the current line.\n");
    printf("Vertical tab \v is tricky, as its behaviour is unspecified in certain conditions.\n");
}

