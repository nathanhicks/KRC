#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
void reverse(int len, char s[]);
void copy(char to[], char from[]);

int main()
{
  int len;
  char s[MAXLINE];

  while ((len = getline(s, MAXLINE)) > 0) {
    reverse(len,s);
    printf("%s\n", s);
  }

  return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
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

void reverse(int len,char s[])
{
  int i,j;
  char t[MAXLINE];
  j = 0;
  for(i = len-1; i >= 0; i--) {
    t[j] = s[i];
    j++;
  }
  t[j+1] = '\n';
  t[j+2] = '\0';

  /* Copy t back to s */
  copy(s,t);
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
