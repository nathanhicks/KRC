/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x.  Explain why.  Use this observation to write a faster version of
bitcount */

/* Explanation:
    
Let x =   0101 = 5  Let a = 0110 = 6  Let h = 1011 1000
Let y = & 0100 = 4  Let b = 0101 = 5  Let k = 1011 0111
        --------            ---------         ---------
          1110              0100 = 4          1011 1000
          
The rightmost bit of x and x-1 are never the same, so the AND result will always
yield a FALSE rightmost bit.  More information on two's complement is on
Wikipedia
*/
#include<stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x);

int main(void)
{
    unsigned x = 5438;
    printf("b = %d\n", bitcount(x));
    return 0;
}

int bitcount(unsigned x)
{
    int b = 0;
    
    while(x != 0) {
        // 2's complement system, delete the rightmost 1-bit in x
        x &= (x-1);
        b++;
    }
    return b;
}