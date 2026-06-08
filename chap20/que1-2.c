#include <stdio.h>

int main(void)
{
    unsigned int i, j;
    j = 4;
    i = 16;
    i ^= (1 << j);
    printf("%u\n", i);

    return 0;
}