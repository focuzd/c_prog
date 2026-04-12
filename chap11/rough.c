#include <stdio.h>

int main(void)
{
    int *p;
    double x;

    x = 3.75;
    p = &x;
    printf("%p: %d\n", p, *p);

    return 0;
}
