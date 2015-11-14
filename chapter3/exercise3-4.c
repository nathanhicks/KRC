/* Exercise 3-4.  In a two's complement number representation, our version of
 * itoa does not handle the largest negative number, that is, the value of n
 * equal to -(2^wordsize-1).  Explain why not.  Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 */

 /* Explanation:

 In a two's complement number representation,  2147483648 cannot be represented
 in a signed 32-bit integer, so we have to display it either as an unsigned long
 int, or a long long int.

 My solution simply changes the data type from a 32-bit int to an unsigned long
 */

#include<stdio.h>
#include<string.h>
#include<limits.h>

void itoa(unsigned long n, char s[]);
void reverse(char s[]);

int main(void)
{

  char s[1000];
  itoa(INT_MIN,s);
  printf("%s",s);
  return 0;
}

/* itoa:  convert n to characters in s */
void itoa(unsigned long  n, char s[])
{
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;           /* make n positive */
  i = 0;
  do {        /* generate digits in reverse order */
    s[i++] = n % 10 + '0';    /* get next digit */
  } while ((n /= 10) > 0);    /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
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
