/* reverse_rec:  recursive version of func reverse(s) */

void reverse_rec(char s[], int l, int r)
{
    int c;

    if (l < r) {
        reverse_rec(s, l+1, r-1);
        c = s[l];
        s[l] = s[r];
        s[r] = c;
    }
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "hello";
    reverse_rec(s, 0, (strlen(s) - 1));
    printf("%s\n", s);
    
    return 0;
}
