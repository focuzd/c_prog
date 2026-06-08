#include <stdio.h>

struct {
    unsigned int flag : 1;
}s;

int main(void)
{
    printf("%zu\n", sizeof(s));

    return 0;
}