#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
main()
{
    float *fp, *cp;
    float fahr = 0.0, celsius = 0.0;
    int lower, upper, step;

    lower = 0;  /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = upper;
    fp = &fahr;
    cp = &celsius;
    printf("%3s\t%6s\n", "Fahrenheit", "Celsius");
    printf("%3s\t%6s\n", "----------", "-------");
    while (fahr >= lower) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t%12.1f\n", *fp, *cp);
        fahr = fahr - step;
    }
}
