/*
 * hello2.c
 * uses printComma() in main()
 * created by Anvesh G. Jhuboo
 * on 2021/2/2
 */

#include <stdio.h>

void printComma()
{
    printf( ", " );
    return;
}

int main()
{
    printf( "Hello" );
    printComma();
    printf( "world!\n" );
    return 0;
}

/* eof */
