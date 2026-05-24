#include <stdio.h>
#include "readline.h"

int read_line(char* str, int len)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < len)
            str[i++] = ch;
    str[i] = '\0';

    return i;
}