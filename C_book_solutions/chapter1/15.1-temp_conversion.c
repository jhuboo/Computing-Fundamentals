#include <stdio.h>

int fahr_celsius(int fahr);

/* Rewrite the temperature conversion program used earlier */
main()
{
    int fahr;

    printf("Fahr Celsius\n");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6d\n", fahr, fahr_celsius(fahr));

    return 0;
}

/* fahr_celsius - fahr to celsius converter */
int fahr_celsius(int t)
{
    int celsius;

    celsius = (5.0 / 9.0) * (t - 32.0);

    return celsius;
} 
