#include <stdio.h>

int main(void) {
	int i, t[5];
	for(i = 0; i < 5; i++)
		t[i] = 2 * i;
	i = 0;
	for (i = 0; i < 5; i++)
		i += t[i];
	printf("%d\n", i);
	return 0;
}
