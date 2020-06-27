/* There is a bug in this program where it doesn't output
    the correct number of elements by length.
    Need to be looked into */

#include <stdio.h>

/* Prints a histogram of the length of the words in the input
    Vertical version */
main()
{
    int len_freq[11];           /* Stores the freq of each length */
    int length, height;         /* Stoes actual length and highest freq */
    int c, i, k;

    length = height = 0;        /* Start with current length and highest */

    /* Initialize each ele in the len_freq array */
    for (i = 0; i <= 10; ++i)
        len_freq[i] = 0;

    /* Reads the input storing each frequency */
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t')
            ++length;
        else if (length != 0) {
            if (length <= 10) {
                ++len_freq[length-1];
                if (height < len_freq[length-1])
                    height = len_freq[length-1];
            }
            else {
                ++len_freq[10];
                if (height < len_freq[10])
                    height = len_freq[10];
            }
            length = 0;
        }
    }


    /* Creates the histogram */
    for (i = height; i > 0; --i) {
        printf("%2d|", i);
        for (k = 0; k <= 10; ++k) {
            if (len_freq[k] >= 1)
                printf("   #");
            else
                printf("    ");
        }
        printf("\n");
    }

    printf("   +");
    for (i = 0; i <= 10; ++i)
        printf("----");
    printf("\n   ");

    for (i = 0; i <= 10; ++i) {
        if (i < 10) 
            printf("%4d", i+1);
        else
            printf("  +10");
    }
    printf("\n");
}
