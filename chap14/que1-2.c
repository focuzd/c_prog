#include <stdio.h>

#define NELEMS(a) ((int)(sizeof(a) / sizeof(a[0])))

int main(void)
{
    int a[35];
    float b[90];
    char c[58];

    printf("%d\n%d\n%d\n", NELEMS(a), NELEMS(b), NELEMS(c));

    return 0;
}