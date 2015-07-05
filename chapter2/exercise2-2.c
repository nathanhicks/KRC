/*
 * Exercise 2-2
 *
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c!= EOF; ++i)
 * 		s[i] = c;
 *
 * Write a loop equivalent to the for loop above without using && or ||.
 */
#include <stdio.h>

int main() {
	int c,i,lim;
	lim = 30;
	int s[lim];
	c = i = 0;

	for (i=0; i<lim-1; ++i)
		if((c=getchar()) != '\n') {
			if(c != EOF) {
				s[i] = c;
			} else {
				break;
			}
		} else {
			break;
		}

}
