/* Exercise 4-1.  Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 */
#include<stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
  char line[MAXLINE];
  int found = 0;

  while (getline(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

 /* returns the position of the rightmost occurrence of t in s, or -1 if there
  * is none.
  */
int strrindex(char s[],char t[])
{
  int i, j, k;

  /* outer loop iterates through every character in s */
  for (i = 0; s[i] != '\0'; i++) {
    /* inner loop iterates until the end of the string and as
     * long as the current index in s is equal to the current position
     * in t
     */
    for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
      ;
    /* if there were any matches, k will be greater than zero */
    if (k > 0 && t[k] == '\0')
      return j;
      //return i;
  }
  return -1;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
