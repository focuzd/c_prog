#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void)
{
    printf("%x\n", rotate_left(0x12345678, 3));
    printf("%x\n", rotate_right(0x12345678, 5));
    return 0;
}

unsigned int rotate_left(unsigned int i, int n)
{
    unsigned int shifted;
    shifted = i >> (sizeof(unsigned int) * 8 - n);
    return (i << n) | shifted;
}

unsigned int rotate_right(unsigned int i, int n)
{
    unsigned int shifted;
    shifted = i << (sizeof(unsigned int) * 8 - n);
    return (i >> n) | shifted;
}