#include <stdio.h>

int *find_largest(int a[], int n);

int main(void)
{
    int n, i, *largest;
    scanf("%d", &n);

    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    largest = find_largest(a, n);
    printf("largest(%p): %d\n", largest, *largest);

    return 0;
}

int *find_largest(int a[], int n)
{
    int i, *largest;

    largest = &a[0];
    for (i = 0; i < n; i++) 
        if (a[i] > *largest)
            largest = &a[i];

    return largest;
}
