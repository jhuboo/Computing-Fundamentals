#include <stdio.h>

int main(void) {
	int t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *p = t;

	p += 2;
	p += p[-1];
	printf("%d\n", *p);
	return 0;
}
