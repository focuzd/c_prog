#include <stdio.h>

int main(void)
{
    char a, b, c, d;
    if ('\b' == '\x8')
        printf("1. Correct\n");
    if ('\n' == '\xA')
        printf("2. Correct\n");
    if ('\r' == '\xD')
        printf("3. Correct\n");
    if ('\t' == '\x9')
        printf("4. Correct\n");
    return 0;
}
