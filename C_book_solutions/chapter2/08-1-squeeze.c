enum bool { NO, YES };

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
        if (! contains(s2, s1[i]))
            s1[j++] = s1[i];

    s1[j] = '\0';
}

int contains(char str[], char c)
{
    int i = 0;
    while (str[i] != '\0')
        if (c == str[i++])
            return YES;

    return NO;
}
