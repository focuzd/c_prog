#include <stdio.h>
#include <stdbool.h>

bool has_zero(int a[], int n);

int main(void)
{
    int n, i;
    scanf("%d", &n);
    int a[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d\n", has_zero(a, n));

    return 0;
}

bool has_zero(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (a[i] == 0)
            return true;
    
    return false;
}
