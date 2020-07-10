/* 'x' is an integer (char constant), used to represent the numeric value of x
    "x" is a string that contains a single character;
    it is an array of characters with the letter 'x' and a '\0' */

/* We also have enumeration constants */
/* Enumerations provide a convinient way to associate constant values with names
    an alternative to #define with the advantage that values can be 
    generated for you */
enum boolean ( NO, YES );

enum escapes ( BELL = '\a', BACKSPACE = '\b', TAB = '\t',
               NEWLINE = '\n', VTAB = '\v', RETURN = '\r' );

enum months ( JAN = 1, FEB, MAR, APR, MAY, JUN,
              JUL, AUG, SEP, OCT, NOV, DEC );
                    /* FEB = 2; MAR = 3, etc. */
