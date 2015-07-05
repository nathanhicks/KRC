#include <stdio.h>

#define MAX_BUFFER 1024
#define MAX_COLUMNS 80

int getline(char line[], int maxline);

int main()
{
  int len,index,j;
  len = index = j = 0;
  char line[MAX_BUFFER];
  
  while(( len = getline(line, MAX_BUFFER)) > 0) {
      if ( len > MAX_COLUMNS ) {
          index = 0;
          while( len > 0 ) {
              if(index > 0) { /* more than 80 columns for this line */
                  putchar('\t');
              }
              for(j = 0; j < MAX_COLUMNS && j < len; ++j) {
                  putchar(line[index]);
                  ++index;
              }
              putchar('\n');
              len -= j;
          }
      } else {
          printf("%s",line);
      }
  }
  return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
      s[i] = c;
  if (c == '\n') {
      s[i] = c;
      ++i;
  }
  s[i] = '\0';
  return i;
}
