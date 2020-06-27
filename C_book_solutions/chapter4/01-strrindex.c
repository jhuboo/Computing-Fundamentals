/* Write a function strrindex(s, t) which returns the position of the
    rightmost occurence of t in s, or -1 if there is none */

int strrindex(char s[], char t[])
{
    int i;
    int count = -1;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == t)
            count = i;

    return count;
}
