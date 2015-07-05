#include <stdio.h>

main()
{
	int c = 0;
	int has_blank = 0;

	while ((c = getchar()) != EOF) {
		if ( has_blank == 0 || c != ' ')
			putchar(c);
		if ( c == ' ' )
			has_blank = 1;
		else
			has_blank = 0;
	}

}
