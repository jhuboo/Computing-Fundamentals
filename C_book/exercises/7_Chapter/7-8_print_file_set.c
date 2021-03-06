/* Print a set of files, starting each new one on a new page,
 * with a title, and a running page count for each file
 *
 * created by Anvesh G. Jhuboo
 * on Feb/20/21
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXBOT  3   /* max # lines at bottom page */
#define MAXHDR  5   /* max # lines at head of page */
#define MAXLINE 100 /* max size of one line */
#define MAXPAGE 66  /* max # lines on one page */

/* print: print files - each new one on a new page */
int main(int argc, char *argv[])
{
    FILE *fp;
    void fileprint(FILE *fp, char *fname);

    system("date");     /* print date */

    if (argc == 1)      /* no args: print standard input */
        fileprint(stdin, " ");
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "print: can't open %s\n", *argv);
                exit(1);
            } else {
                fileprint(fp, *argv);
                fclose(fp);
            }

    return 0;
}


/* fileprint: print file fname */
void fileprint(FILE *fp, char *fname)
{
    int lineno, pageno = 1;
    char line[MAXLINE];
    int heading(char *fname, int pageno);

    lineno = heading(fname, pageno++);

    while (fgets(line, MAXLINE, fp) != NULL) {

        if (lineno == 1) {
            fprintf(stdout, "\f");
            lineno = heading(fname, pageno++);
        }

        fputs(line, stdout);

        if (++lineno > MAXPAGE - MAXBOT)
            lineno = 1;
    }

    fprintf(stdout, "\f");      /* page eject after the line */
}


/* heading: put heading and enough blank lines */
int heading(char *fname, int pageno)
{
    int ln = 3;

    fprintf(stdout, "---------------------------\n\n");
    fprintf(stdout, "%s     page %d\n", fname, pageno);
    fprintf(stdout, "---------------------------\n\n");
    while (ln++ < MAXHDR)
        fprintf(stdout, "\n");

    return ln;
}
