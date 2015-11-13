/*
Exercise 3-3.  Write a function expand(s1,s2) that expands shorthand notations
like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z.  Arrange that a leading or trailing - is taken
literally.
*/

#include<stdio.h>

void expand(char s1[],char s2[]);

int main(void)
{
    char s1[] = "a-z,A-Z0-9";
    char s2[1000];
    expand(s1,s2);
    printf("%s\n",s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i,j; 
    for(i = 0,j = 97; j <= 122; i++,j++) {
        s2[i] = j;
    }
    /*for(i = 0,j = 65; j <= 90; i++,j++) {
        s2[i] = j;
    }*/
    /*for(i = 0,j = 0; j <= 9; i++,j++) {
        s2[i] = j;
    }*/
    
}