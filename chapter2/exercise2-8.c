// Write a function rightrot(x,n) that returns the value of the integer x
// rotated to the right by n bit positions.
#include<stdio.h>

unsigned rightrot(unsigned x, int n);
unsigned getbits(unsigned x, int p, int n);
void dec2bin(unsigned x);

int main(void)
{
    unsigned x = 170;
    int n = 3;
    int result = rightrot(x,n);
    
    printf("x   = ");dec2bin(x);
    printf("n   = ");dec2bin(n);
    printf("result   = ");dec2bin(result);
    return 0;
}

/* returns the value of the integer x rotated
    to the right by n bit positions
*/
unsigned rightrot(unsigned x, int n)
{
    return x >> n;
}

/* getbits: get n bits from position p from K&R p. 49 */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* Prints the 32-bit binary form of a decimal value */
void dec2bin(unsigned x)
{
    char i;
    
    for (i = 32-1; i >= 0; i--) {
        printf("%d", getbits(x,i,1));
        if(!(i%8)) {
            putchar(' ');
        }
    }
    printf(" = %d\n",x);
}