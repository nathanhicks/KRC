#include <stdio.h>

main()
{
    float *fp, *cp;
    float fahr = 0.0, celsius = 0.0;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    fahr = lower;
    fp = &fahr;
    cp = &celsius;
    printf("%3s\t%6s\n", "Celsius", "Fahrenheit");
    printf("%3s\t%6s\n", "----------", "-------");
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32;
        printf("%3.0f\t%12.1f\n", *cp, *fp);
        celsius = celsius + step;
    }
}
