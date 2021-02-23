/*
 * hello3.c
 * use printComma() & printWord() in main()
 * created by Anvesh G. Jhuboo
 * on 2021/2/2
 */

#include <stdio.h>

void printComma(void)
{
    printf( ", " );
}

void printWord(char* word)
{
    printf( "%s", word );
}

int main()
{
    printWord( "Hello" );
    printComma();
    printWord( "world" );
    printf( "!\n" );
}

/* eof */
