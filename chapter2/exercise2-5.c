/*
 * Exercise 2-5
 *
 * Write the function any(s1,s2), which returns the first location in the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2.  (The standard library function strpbrk does the same job
 * but returns a pointer to the location.)
 */

#include <stdio.h>

int any(char s1[],char s2[]);

int main()
{
	char s1[] = "mom";
	char s2[] = "Tomb";
	int index;

	index = any(s1,s2);
	if( index ) {
		printf("Match at index=%d\n",index);
	} else {
		printf("No match found.\n");
	}

	return 0;
}

int any(char s1[], char s2[])
{
	int i,k,j;
	for(i = 0; s2[i] != '\0'; i++) {
		for (k = j = 0; s1[k] != '\0'; k++) {
			if (s1[k] == s2[i]) {
				return k;
			}
		}
	}
	return -1;
}
