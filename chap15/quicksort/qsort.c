#include <stdio.h>
#include "quick-sort.h"

int main(void)
{
    int n, i;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);
    printf("In sorted order:");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    putchar('\n');

    return 0;
}