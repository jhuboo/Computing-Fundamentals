#include <stdio.h>

int main(void) {
	char a, z, spc;
	a = 'A';
	spc = ' ';
	z = 'Z';

	printf("%c: %i\n", a, a);
	printf("%c: %i\n", z, z);
	printf("%c: %i\n", spc, spc);
	return 0;
}
