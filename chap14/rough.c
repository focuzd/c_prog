#include <stdio.h>

#define STR(x) #x
#define M2(x, y) #x #y
#define STR2(x) STR(x)

#define LINE_FILE ("Line " STR2(__LINE__) " of file " __FILE__)

int main(void)
{
    int i = 5, j = 6;
    printf("%s\n", LINE_FILE);
    puts(M2(i, j));
    return 0;
}