#include <stdio.h>

#define MAX_BUFFER 1024

int main()
{
    int x;
    int in_comment,len;
    int in_quote;
    char line[MAX_BUFFER];

    while ((len = getline(line, MAX_BUFFER)) > 0) {
        x=0;
        while( x < len) {
            if( line[x] == '"') {
                in_quote = 1;
            }
            if ( ! in_quote )
            {
                if (line[x] == '/' && line[x+1] == '*') {
                    x=x+2;
                    in_comment = 1;
                }
                if (line[x] == '*' && line[x+1] == '/') {
                    x=x+2;
                    in_comment = 0;
                }
                if(in_comment == 1) {
                    x++;
                }
                else {
                    printf ("%c", line[x]);
                    x++;
                }
            }
            else
            {
                printf ("%c", line[x]);
                x++;
            }
        }
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
