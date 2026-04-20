#include <stdio.h>

#define LEN 10

int sum_two_dimensional_array(const int a[][LEN], int n)
{
    const int *p;
    int sum = 0;

    for (p = a[0]; p <= &a[n-1][LEN-1]; p++) 
        sum += *p;

    return sum;
}

int main(void)
{
    int a[5][LEN] = {0};
    a[1][3] = 10;
    a[0][7] = 2;
    a[4][9] = 8;

    printf("sum: %d\n", sum_two_dimensional_array(a, 5));

    return 0;
}
