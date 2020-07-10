/* itoa with one more arg, which is field width
    converted number should be padded with blanks on the left
    to make it wide enough */
void itoa(int n, char s[], int width)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = n % 10 + '0';
        printf("%d %% %d + '0' = %d\n", n, 10, s[i-1]);
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < width)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}
