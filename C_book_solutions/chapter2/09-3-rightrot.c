/* rightrot(x, n): returns the value of integer x rotated to the right
    by 'n' bit positions    */
unsigned rightrot(unsigned x, unsigned n)
{
    while (n > 0) {
        if ((x & 1) == 1)
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = (x >> 1);
        n--;
    }

    return x;
}


/* adding main driver */
#include <stdio.h>

int main(void)
{
    unsigned x;
    int n;

    for (x = 0; x < 700; x += 49)
        for (n = 1; n < 8; n++)
            printf("%u, %d: %u\n", x, n, rightrot(x, n));

    return 0;
}
