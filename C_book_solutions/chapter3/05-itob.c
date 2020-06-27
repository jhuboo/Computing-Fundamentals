/* itob:    converts the integer n into a base b character repr
    in the string s. In particular, itob(n,s,16) formats s as a hex in s */
void itob(int n, char s[], int b)
{
    int i, sign, r;

    sign = n;
    i = 0;

    do {
        r = n % b;
        if (sign < 0)
            r = -r;
        s[i++] = (r > 9 ? (r-10 + 'A') : (r + '0'));
    } while (n /= b);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int i, j, t;

    for (j = 0; s[j] != '\0'; j++)
        ;

    for (i = 0, --j; j > i; i++, j--) {
        t = s[j];
        s[j] = s[i];
        s[i] = t;
    }
}
