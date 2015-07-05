#include <stdio.h>

/* copy input to output; 1st version */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
      if( getchar() != EOF ) {
        printf("End of File has been reached.\n");
      } else {
        printf("End of File has not been reached.\n");
      }
      putchar(c);
    }
}
