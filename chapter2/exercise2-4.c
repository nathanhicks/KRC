/*
 * Exercise 2-4
 *
 * Write an alternate version of squeeze(s1,s2) that deletes each character in
 * s1 that matches any character in the string s2.
 */
#include <stdio.h>

void squeeze(char s1[],char s2[]);

int main()
{
	char s1[6] = {'t','e','s','t','i','\0'};
	char s2[4] = {'t','e','\0'};
	squeeze(s1,s2);
	printf("%s\n",s1);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i,j,k;

	for (i = 0; s2[i] != '\0'; i++) {
		for (k = j = 0; s1[k] != '\0'; k++) {
			if (s1[k] != s2[i]) {
				s1[j++] = s1[k];
			}
		}
		s1[j] = '\0';
	}
}
