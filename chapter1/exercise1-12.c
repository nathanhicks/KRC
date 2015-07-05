#include <stdio.h>

main()
{
	int c = 0;
	while ((c = getchar()) != EOF) {
		putchar(c);
		if ( c == ' ' || c == '\t' || c == '\n') 
			putchar('\n');
	}
}
