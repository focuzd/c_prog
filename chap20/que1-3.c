#include <stdio.h>

#define SWAP(x, y) (((x) ^= (y)), ((y) ^= (x)), ((x) ^= (y)))

int main(void)
{
    int i, j;
    i = -4;
    j = 11;

    SWAP(i, j);
    printf("i=%d j=%d\n", i, j);

    return 0;
}