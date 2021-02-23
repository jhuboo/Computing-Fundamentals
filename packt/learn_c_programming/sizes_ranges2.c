/*
 * sizes_ranges2.c
 * provides ranges for each data types.
 * created by Anvesh G. Jhuboo
 * on 2021/Feb/3
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

// funtion prototypes
void printRanges( void );

int main( void ) {
    printRanges();
}

// printRanges() provides ranges for each data type
void printRanges( void ) {
    printf("Ranges for interger data types in C\n\n");
    printf("int8_t %22d %20d\n", SCHAR_MIN, SCHAR_MAX);
    printf("int16_t %21d %20d\n", SHRT_MIN, SHRT_MAX);
    printf("int32_t %21d %20d\n", INT_MIN, INT_MAX);
    printf("int64_t %21lld %20lld\n", LLONG_MIN, LLONG_MAX);
    printf("uint8_t %21d %20d\n", 0, UCHAR_MAX);
    printf("uint16_t %20d %20d\n", 0, USHRT_MAX);
    printf("uint32_t %20d %20u\n", 0, UINT_MAX);
    printf("uint64_t %20d %20llu\n", 0, ULLONG_MAX);
    printf("\n");
    printf("Ranges for real number data types in C\n\n");
    printf("float %18.7g %14.7g\n", FLT_MIN, FLT_MAX);
    printf("double %18.7g %14.7g\n", DBL_MIN, DBL_MAX);
    printf("long double %14.7Lg %14.7Lg\n", LDBL_MIN, LDBL_MAX);
    printf("\n");
}
