/*
Exercise 3-2.  Write a function escape(s,t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the
string t to s.  Use a switch.  Write a function for the other direction as well,
converting escape sequences into the real characters.
*/
#include<stdio.h>
#include<string.h>

char * escape(char s[],char t[]);
char * unescape(char s[], char t[]);

int main(void)
{
    char t[] = "he\tllo\n";
    char s[10];
    char w[10];
    printf("Original String = '%s'\n",t);
    escape(s,t);
    printf("Escaped String = '%s'\n",s);
    unescape(s,w);
    printf("Unescaped String = '%s'\n",w);
    return 0;
}

char * escape(char s[], char t[])
{
    int i,j;
    for(i = j = 0; j < strlen(t); j++,i++) {
        switch (t[j]) {
            // TAB
            case 9:
                s[i] = '\\';
                s[++i] = 't';
                break;
            // NL
            case 10:
                s[i] = '\\';
                s[++i] = 'n';
                break;
            default:
                s[i] = t[j];
                break;
        }
    }
    return s;
}

char * unescape(char s[], char t[])
{
    int i,j;
    for(i = j = 0; j < strlen(s); j++) {
        switch(s[j]) {
            case '\\':
                break;
            case 't':
                t[i++] = 9;
                break;
            case 'n':
                t[i++] = 10;
                break;
            default:
                t[i++] = s[j];
                break;
        }
    }
    return t;
}