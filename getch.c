#include <stdio.h>
#include "calc.h"

static char buf[BUFFSIZE];  // buffer for ungetch
static int bufp = 0;        // next free position in buf

int getch(void)      // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}