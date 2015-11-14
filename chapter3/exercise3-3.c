/*
Exercise 3-3.  Write a function expand(s1,s2) that expands shorthand notations
like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z.  Arrange that a leading or trailing - is taken
literally.
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

void expand(char s1[],char s2[]);

int main(void)
{
    char s1[] = "-a-z,A-Z0-9-a-z0-9a-b-c";
    char s2[1000];
    expand(s1,s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i,j,k;
    char c1,c2,c3;

    while(k < strlen(s1)) {
      /* The following 3 if statements are looking for an a-z,A-Z,or 0-9 pattern */
      c1 = s1[k];
      if (isdigit(c1) || isalpha(c1) || islower(c1) || isupper(c1)) {
        c2 = s1[k+1];
        if (c2 == '-') {
          c3 = s1[k+2];
          if (isdigit(c3) || isalpha(c3) || islower(c3) || isupper(c3)) {
            for(i = 0,j = c1; j <= c3; i++,j++) {
              s2[i] = j;
            }
          }
        }
        s2[i] = '\0';
        printf("%s\n",s2);
        k+=3;
      } else {
        k+=1;
      }
    }
}
