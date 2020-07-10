#include <stdio.h>

#define MAXWORDLEN 10
#define IN          1
#define OUT         0

/* Print a histogram of the length of words in the input
    this will be a horizontal histogram */
main()
{
    int c = EOF;
    int i = 0;
    int j = 0; 
    int arr_of_len[MAXWORDLEN + 1];
    int state = IN;
    int nc = 0;

    /* initialize the array */
    for (i = 0; i <= MAXWORDLEN; ++i)
        arr_of_len[i] = 0;

    /* getchar() and find out the length of each word
        assigning them to the position in the array */
    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            --nc;
        }

        if (state == OUT) {
            if (nc != 0 && nc <= MAXWORDLEN) {
                ++arr_of_len[nc];

            state = IN;
            nc = 0;
            }
        }
    }

    /* build the histogram
        using the filled array from above */
    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("|%2d| ", i);

        for (j = 0; j < arr_of_len[i]; ++j) 
            putchar('*');

        putchar('\n');
    }
}
