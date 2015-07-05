#include <stdio.h>

main()
{
  int c = 0;
  long bc = 0, tc = 0, nc = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      bc++;
    else if (c == '\t')
      tc++;
    else if (c == '\n')
      nc++;
  }
  printf("blank count = %ld, tab count = %ld, newline count =  %ld\n",bc,tc,nc);

}
