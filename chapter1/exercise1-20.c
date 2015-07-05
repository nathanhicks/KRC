#include <stdio.h>

#define TAB '\t'
#define SPACE	' '

int main()
{
  int c,col;
	int TabSize = 5;
  col = 0;

  while ((c = getchar()) != EOF) {
		if(c == '\n')
			col = 0;  /* reset column counter */
    if (c == TAB) {
      for(col; (col % TabSize) != 0; col++) {
        putchar(SPACE);
      }
    } else {
      putchar(c);
			col++;
    }
  }

  return 0;
}
