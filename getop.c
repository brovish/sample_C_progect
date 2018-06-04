#include "calc.h"
#include "stdio.h"
#include <ctype.h>

static char buf[BUFFSIZE];  // buffer for ungetch
static int bufp = 0;

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;                  // not a number
    i = 0;
    if (isdigit(c))              // collect integer part
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')                // collect fraction part
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        if (bufp >= BUFFSIZE)
            printf("ungetch: too many characters\n");
        else buf[bufp++] = c;
    return NUMBER;
}