#include <stdio.h>

#define STR(x) #x
#define STR2(x) STR(x)

#define LINE_FILE ("Line " STR2(__LINE__) " of file " __FILE__)

int main(void)
{
    printf("%s\n", LINE_FILE);
    return 0;
}