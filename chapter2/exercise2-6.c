/*
 * Exercise 2-6
 *
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 * 
 */
#include <stdio.h>

/* setbits: exercise solution (see function definition) */
unsigned setbits(unsigned x, int p, int n, int y);
/* getbits: get n bits from position p (from K&R p.49) */
unsigned getbits(unsigned x, int p, int n);
/* Prints the 32-bit binary form of a decimal value */
void dec2bin(unsigned x);

int main(void)
{
	int x,y,p,n;
	x = 170;
	p = 4;
	n = 3;
	y = 15;

	printf("x = ");	dec2bin(x);
	printf("p = ");	dec2bin(p);
	printf("n = ");	dec2bin(n);
	printf("y = ");	dec2bin(y);
	printf("**Call to setbits\n");
	setbits(x,p,n,y);

	return 0;
}

/* setbits(x,p,n,y):
 *
 * Returns x with the n bits that begin at position p set to the rightmost n
 * bits of y, leaving the other bits unchanged
 */
unsigned setbits(unsigned x,int p,int n,int y)
{
	int r,rightmost_nbits_y,shift_value,x_bitmask,lhs,rhs;
	// For comment explanation purposes, Let x=10101010, p=4, n=3, y=15

	/* Task #1: Store rightmost n bits of y 
	 * In general, 1<<N-1 creates a number with N ones in binary form.
	 * 1 << n = 0b1000.  So ((1<<n)-1) = 0b0111.
	 */
	r = (1<<n)-1; // Another method is ~(~0<<n)
	 /* y & r will extract the last N bits of y, for example
	 *   00001111 = 15
	 * & 00000111 = 7
	 * -----------
	 *   00000111 = 7
	 */
	rightmost_nbits_y = y & r;

	/* Task #2: Shift the rightmost bits of y to position p
	 * This will set us up to execute bitwise logic operations
	 * against x.
	 *
	 * Position p is 0-indexed, while n is 1-indexed
	 * Get number of places needed to shift to position p
	 * Which is the difference between p and n
	 * (4+1-3) = 2
	 */
	shift_value = (p+1-n);
	/* We now need to position the rightmost n bits of y at position p
	 * This will put those bits in position to allow us to do a bit-wise
	 * OR operation against x to achieve the desired end result
	 * rhs = 0000 0111 << 2 = 0001 1100
	 */
	rhs = rightmost_nbits_y << shift_value;

	/* Task #3: Create a bitmask for x
	 * (r << shift_value) = (00000111 << 2) = 00011100
	 * ~00011100 = 11100011
	 */
	x_bitmask = ~(r << shift_value);

	/* Task #4: x & x_bitmask
	 * LHS = 10101010 & 11100011 = 10100010
	 */
	lhs = x & x_bitmask;
	// Uncomment for debug purposes
	// print binary representation to stdout
	printf("r = ");dec2bin(r);
	printf("y = ");dec2bin(y);
	printf("rightmost_nbits_y = ");dec2bin(rightmost_nbits_y);
	printf("rhs = ");dec2bin(rhs);
	printf("x = ");dec2bin(x);
	printf("x_bitmask = ");dec2bin(x_bitmask);
	printf("lhs = ");dec2bin(lhs);
	printf("lhs | rhs = ");dec2bin(lhs | rhs);
	
	/* Task #5: lhs | rhs = solution
	 * Let lhs = 10100010, rhs = 00011100
	 * 10100010 | 00011100 = 10111110
	 *
	 * Without the intermediary steps, setbits could have been a one-liner:
	 * return (x & ~(((1 << n)-1) << (p+1-n))) | (y & ((1<<n)-1) << (p+1-n))
	 */
	return lhs | rhs;
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
