#include <stdio.h>

int *find_largest(int a[], int n)
{
    int *p, *max;
    
    max = a;
    for (p = a; p < a + n; p++)
        if (*p > *max)
            max = p;

    return max;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);

    printf("%d\n", *(find_largest(a, n)));

    return 0;
}
