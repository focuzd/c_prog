#include <stdio.h>

int sum_array(const int a[], int n)
{
    int sum;
    const int *p;
    sum = 0;

    for (p = a; p < a + n; p++)
        sum += *p;

    return sum;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    printf("%d\n", sum_array(a, 5));
    return 0;
}
