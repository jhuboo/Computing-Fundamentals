/* invert(x, p, n): returns x with the 'n' bits that begin at position p inverted
    ie. ( 1 is changed to 0, and vice-versa, leaving the others unchanged) */
unsigned invert(unsigned x, int p , int n)
{
    return x ^ ((~(~0 << n)) << p + 1 - n);
}

#include <stdio.h>

int main(void)
{
    unsigned x;
    int p, n;

    for (x = 0; x < 700; x += 49)
        for (n = 0; n < 8; n++)
            for (p = 0; p < 8; p++)
                printf("%x, %d, %d: %x\n", x, p, n, invert(x, p, n));

    return 0;
}
