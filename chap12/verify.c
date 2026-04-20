#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = a;
    printf("%d\n", p == a[0]);

    return 0;
}


