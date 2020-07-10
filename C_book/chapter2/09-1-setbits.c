#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    unsigned i, j, k;
    int p, n;

    for (i = 0; i < 100; i += 50)
        for (j = 0; j < 10; j += 1)
            for (p = 0; p < 16; p++)
                for (n = 1; n <= p + 1; n++) {
                    k = setbits(i, p, n, j);
                    printf("setbits(%u, %d, %d, %u) = %u\n", i, p, n, j, k);
                }
    return 0;
}

/* setbits(x, p, n, y): returns x with the 'n' bits that begin at position p
    set to the rightmost 'n' bits of y, leaving the other bits unchanged */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ((-0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n));
}
