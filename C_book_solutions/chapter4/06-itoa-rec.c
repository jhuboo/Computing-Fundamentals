int itoa_rec(int n, char s[], int base, int p)
{
    int d = n % base;
    int r = n / base;
    if (n < 0) {
        d = -d;
        r = -r;
    }

    if (r)
        p = itoa_rec(r, s, base, p);
    
    s[p++] = "0123456789abcdefghijklmnopqrstuvwxyz"[d];
    return p;
}

void itoa(int n, char s[], int base)
{
    int p = 0;
    if (n < 0)
        s[p++] = '-';
    
    s[itoa_rec(n, s, base, p)] = 0;
}
