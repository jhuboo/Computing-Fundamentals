#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("\nBits of type char: %d\n\n", CHAR_BIT);
    
    printf("Max value of type char: %d\n", CHAR_MAX);
    printf("Min value of type char: %d\n", CHAR_MIN);

    printf("Max value of signed char: %d\n", SCHAR_MAX);
    printf("Min value of signed char: %d\n", SCHAR_MIN);

    printf("Max value of unsigned char: %u\n\n", (unsigned) UCHAR_MAX);
    
    printf("Max value of type short: %d\n", SHRT_MAX);
    printf("Min value of type short: %d\n", SHRT_MIN);

    printf("Max value of type unsigned short: %u\n\n", (unsigned) USHRT_MAX);

    printf("Max value of type int: %d\n", INT_MAX);
    printf("Min value of type int: %d\n\n", INT_MIN);

    printf("Max value of type unsigned int: %u\n\n", UINT_MAX);

    printf("Max value of type long: %ld\n", LONG_MAX);
    printf("Min value of type long: %ld\n", LONG_MIN);

    printf("Max value of type unsigned long: %lu\n\n", ULONG_MAX);

    return 0;
}
