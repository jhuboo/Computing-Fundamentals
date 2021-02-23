/*
 * hello4.c
 * combines printComma() & printWord() into printGreeting()
 * uses printGreeting in main()
 * created by Anvesh G. Jhuboo
 * on 2021/2/2
 */

#include <stdio.h>

void printComma() {
    printf( ", " );
}

void printWord( char* word ) {
    printf( "%s", word );
}

void printGreeting( char* greeting, char* addressee ) {
    printWord( greeting );
    printComma();
    printWord( addressee );
    printf( "!\n" );
}

int main() {
    printGreeting( "Hello", "World" );
    printGreeting( "Why hello there!", "Anvesh G. Jhuboo" );
    return 0;
}

/* eof */
