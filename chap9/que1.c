#include <stdio.h>

void selection_sort(int n, int a[]);

int main(void)
{
    int n, i;
    printf("Enter the length of array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the numbers to be sorted: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    selection_sort(n, a);
    printf("In sorted order:");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int n, int a[])
{
    int i, temp, max_idx = 0;

    if (n == 1) return;

    for (i = 0; i < n; i++) {
        if (a[i] > a[max_idx]) {
            max_idx = i;
        }
    }

    temp = a[max_idx];
    a[max_idx] = a[n-1];
    a[n-1] = temp;

    selection_sort(n-1, a);
}
