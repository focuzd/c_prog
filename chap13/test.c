#include <stdio.h>

int main(void)
{
    char *str = "hello";
    str[2] = 'E';
    printf("%s\n", str);

    return 0;
}
