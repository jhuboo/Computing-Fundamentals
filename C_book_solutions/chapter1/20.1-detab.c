#include <stdio.h>

#define MAXLINE 1000        /* max input line length */
#define SPACES     4        /* default tab length */

/* this program replaces tabs in the input with blanks */
main()
{
    char c;
    char without_tab[MAXLINE];      /* line w/o tabs */
    int i, s;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (s = SPACES; s > 0; --s) {
                without_tab[i] = ' ';
                ++i;
            }
        }
        else if (c == '\n') {
            without_tab[i] = '\n';
            ++i;
            without_tab[i] = '\0';
            printf("%s", without_tab);
            i = 0;
        }
        else {
            without_tab[i] = c;
            ++i;
        }
    }
    return 0;
}
