#include <stdio.h>

#define LOWER   0   /* lower limit of table */
#define UPPER   300 /* upper limit of table */
#define STEP    20  /* step size */

/* Convert Celsius to Fahrenheit
    starting from 300, 280, ..., 0 */
main()
{
    int celsius;

    printf("Celsius   Fahr\n");

    for (celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP)
        printf("%3d     %6.1f\n", celsius, (9.0/5.0) * celsius + 32.0);
}
