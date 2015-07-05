#include <stdio.h>

#define TAB '\t'
#define SPACE	' '

void replace(int count,int TabSize);

int main()
{
  int c,count;
	int TabSize = 5;
  count = 0;

  while ((c = getchar()) != EOF) {
		if(c == '\n')
			count = 0;  /* reset counter */
    if (c == SPACE) {
			++count;
			while ((c = getchar()) == SPACE)
				++count;
			replace(count,TabSize);
			/* flush the non-space character that break us out of the while loop */
			putchar(c);
			count = 0;
    } else {
      putchar(c);
    }
  }

  return 0;
}

void replace(int count,int TabSize)
{
	while(count >= 0) {
		if(count >= TabSize) {
			putchar(TAB);
			count -= TabSize;
		} else {
			putchar(SPACE);
			--count;
		}
	}
}
