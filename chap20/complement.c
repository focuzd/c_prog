#include <stdio.h>

int main(void)
{
    unsigned int num = ~0x1f;
    printf("%x\n", num);

    return 0;
}