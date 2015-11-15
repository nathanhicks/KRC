/* Exercise 3-5.  Write the function itob(n,s,b) that converts the integer n
 * into a base b character representation in the string s.  In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s.
 * */
#include<stdio.h>
#include<string.h>
#include<limits.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

void dec2bin(unsigned x,char s[]);
unsigned getbits(unsigned x, int p, int n);
void dec2hex(int n, char s[]);
void dec2oct(int n, char s[]);

int main(void)
{
  int n;
  char s[1000];

  n = 3545;
  itob(n,s,10);
  itob(n,s,16);
  itob(n,s,8);
  itob(n,s,2);
  return 0;
}

void itob(int n, char s[], int b)
{
  switch (b) {
    case 2:
      dec2bin(n,s);
      printf("%s\n",s);
      break;
    case 8:
      dec2oct(n,s);
      reverse(s);
      printf("%s\n",s);
      break;
    case 10:
      printf("%d\n",n);
      break;
    case 16:
      dec2hex(n,s);
      reverse(s);
      printf("%s\n",s);
      break;
    default:
      break;
  }
}

void reverse(char s[])
{
  int c, i, j;

  for (i=0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

/* Prints the 32-bit binary form of a decimal value */
void dec2bin(unsigned x, char s[])
{
  char i;
  int j;

  for (i = 32-1,j = 0; i >= 0; i--,j++) {
    s[j] = getbits(x,i,1)+'0';
    if(!(i%8)) {
//      s[j++] = ' ';
    }
  }
}
/* getbits: get n bits from position p from K&R p. 49 */
unsigned getbits(unsigned x, int p, int n)
{
      return (x >> (p+1-n)) & ~(~0 << n);
}

void dec2hex(int x, char s[])
{
  int i = 0;
  int remainder;
  do {
    if( x < 16) {
      // The 55 corresponds to the ASCII table
      x <= 9 ? (s[i++] = x) : (s[i++] = x+55);
      x /= (int)16; // effectively set x to 0

      // 0x added below for Hex formatting
      s[i++] = 'x';
      s[i++] = '0';
      // printf("X= %d, s[%d] = %d, remainder = %d\n",x,i,s[i],remainder);
    } else {
      remainder = x % (int)16;
      // The 55 corresponds to the ASCII table
      remainder <= 9 ? (s[i++] = remainder+'0') : (s[i++] = remainder+55);
      x /= (int)16; // Throw away that digit's place
      //printf("X= %d, s[%d] = %d, remainder = %d\n",x,i,s[i-1],remainder);
    }
  } while(x != 0);
}

void dec2oct(int n, char s[])
{
  int i = 0;
  int remainder;
  do {
    if( n < 8 ) {
      s[i++] = n+'0';
      //printf("n = %d, s[%d] = %d, remainder = %d\n",n,i,s[i-1],n);
      n /= (int)8;
      s[i] = '\0';
    } else {
      remainder = n % (int)8;
      s[i++] = remainder+'0';
      n /= (int)8;
      //printf("n = %d, s[%d] = %d, remainder = %d\n",n,i,s[i-1],remainder);
    }
  } while(n != 0);
}
