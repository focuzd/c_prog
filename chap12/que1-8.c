#include <stdio.h>

void store_zeros(int *a, int n)
{
    int *p;
    
    for (p = a; p < a + n; p++)
        *p = 0;
}

int main(void)
{
    int n = 8;
    int a[8] = {3, 7, 9, 4};

    store_zeros(a, n);
    for (int *p = a; p < a + n; p++)
        printf("%d", *p);
    printf("\n");

    return 0;
}
