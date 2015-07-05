#include<stdio.h>

/* return x with the n bits that begin at position p inverted
 * leaving the others unchanged*/
unsigned invert(unsigned x,int p,int n);
/* getbits: get n bits from position p (from K&R p.49) */
unsigned getbits(unsigned x, int p, int n);
/* Prints the 32-bit binary form of a decimal value */
void dec2bin(unsigned x);

int main(void)
{
	unsigned x = 170;
	int p = 4;
	int n = 3;

	invert(x,p,n);

	return 0;
}

/* return x with the n bits that begin at position p inverted
 * leaving the others unchanged*/
unsigned invert(unsigned x, int p, int n)
{
	// Generate n 1 bits
	int r = ~(~0 << n);
	int shift_value = (p+1-n);
	// Shift n 1-bits into position p
	int bitmask = r << shift_value;

	// Uncomment to verify values in stdout
	//printf("x     = ");dec2bin(x);
	//printf("rhs   = ");dec2bin(bitmask);
	//printf("x^rhs = ");dec2bin(x^bitmask);
	return x^bitmask;
}

/* getbits: get n bits from position p
 * from K&R p. 49
 */
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
