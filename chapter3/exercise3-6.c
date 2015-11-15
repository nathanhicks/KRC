/* Exercise 3-6.  Write a version of itoa that accepts three arguments instead 
 * of two.  The third argument is a minimum field width; the converted number
 * must be padded with blanks on the left if necessary to make it wide enough.
 */
#include<stdio.h>
#include<string.h>
#include<limits.h>

void itoa(unsigned long n, char s[], int mfw);
void reverse(char s[]);

int main(void)
{
  char s[1000];
  itoa(INT_MIN,s,30);
  printf("%s",s);
  return 0;
}

void itoa(unsigned long n, char s[], int mfw)
{
  int i,j,sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';

  while(i < mfw) {
      s[i++] = 32;
  }
  s[i] = '\0';
  printf("%s\n",s);
  reverse(s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
  int c, i ,j;

  for (i= 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
