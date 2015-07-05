#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
int rstrip(int len, char line[]);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    int cursor;             /* The current position in the array */
    char line[MAXLINE];     /* current input line */ 

    while ((len = getline(line, MAXLINE)) > 0) {
      cursor = rstrip(len,line);
      if (cursor >= 0)
        printf("%s", line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],  int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int rstrip(int len,char line[])
{
  int i;
  for( i = len - 2; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i) 
    ;
  if (i >= 0) {
      line[i+1] = '\n';
      line[i+2] = '\0';
  }
  return i;
}
