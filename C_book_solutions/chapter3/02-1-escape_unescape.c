/* Write a function escape(s, t) that converts characters like newline
    and tab into visible escape sequences like \n and \t as it copies
    the string to s. Use a switch. Write a function for the other
    direction as well, converting escape sequences into real characters */
void escape(char* s, char* t)
{
    int i, j;
    i = j = 0;

    while (t[i]) {
        /* Translate the special character, if we have one */
        switch(t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break
            default:
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }
    s[j] = t[i];    /* Don't forget the null character */
}

/* unescape: reverse function */
void unescape(char* s, char* t)
{
    int i, j;
    i = j = 0;

    while(t[i]) {
        switch(t[i]) {
            case '\\':  /* We found an escape sequence, so translate it */
                switch(t[++i]) {
                    case 'n':
                        s[j] = '\n';
                        break;
                    case 't':
                        s[j] = '\t';
                    default:
                        s[j++] = '\\';
                        s[j] = t[i];
                }
                break;
            default:    /* Not an escape sequence, so just copy the character */
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }
    s[j] = t[i];    /* Don't forget the null character */
}
