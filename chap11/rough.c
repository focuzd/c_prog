#include <stdio.h>

int main(void)
{
    int i, j, *p;
    j = 7;
    i = 10;
    p = &i;
    &i = &j;

    printf("%d %d\n", i, j);
    return 0;
}
