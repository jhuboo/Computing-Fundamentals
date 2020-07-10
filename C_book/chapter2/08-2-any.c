int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                return i;
        }
    }

    return -1;
}


/* another much more efficient implementation with O(m + n) */
int any(char *s1, char *s2)
{
    char array[256];

    int i;
    if (s1 == NULL) {
        if (s2 == NULL)
            return 0;
        else
            return -1;
    }

    for (i = 0; i < 256; i++) {
        array[i] = 0;
    }

    while (*s2 != '\0') {
        array[*s2] = 1;
        s2++;
    }

    i = 0;
    while (s1[i] != '\0') {
        if (array[s1[i]] == 1)
            return i;
        i++;
    }

    return -1;
}
