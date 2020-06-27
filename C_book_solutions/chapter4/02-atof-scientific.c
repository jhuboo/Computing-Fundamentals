/* atof: scientific notation */
double atof(char s[])
{
    double val, power;
    int i, sign, sign2, exponent;

    for (i = 0; isspace(s[i]); i++)
        ;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        sign2 = (s[i] == '.') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;

        for (exponent = 0; isdigti(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');

        if (sign2 == 1) for (i = exponent; i > 0; --i, val *= 10.0);
        if (sign2 == -1) for (i = exponent; i > 0; --i, val /= 10.0);
    }

    return sign * val / power;
}
