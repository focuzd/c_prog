#include <stdio.h>

int main(void)
{
    __int8_t ch = 1;
    ch = ch << 7;
    printf("%zu\n", sizeof(ch));
    printf("%d\n", ch);

    return 0;
}