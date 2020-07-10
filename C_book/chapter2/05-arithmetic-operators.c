/* The binary arithmetic operators are +, -, *, /, and the modulus operator %.
    Integer division truncates any fractional part. */

/* basic logic to calculate leap year */
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    printf("%d is a leap year\n", year);
else
    printf("%d is not a learp year\n", year);

/* The % operator cannot be applied to a float or double */

/* the direction of truncation for '/' and the sign of the result for '%'
    are machine-dependent for negative operands, as is
    the action taken on overflow or underflow */

