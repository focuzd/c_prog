#include <stdio.h>

void find_two_largest(const int *a, int n, int *largest,
        int *second_largest)
{
    const int *p;
    if (*a > *(a+1)) {
        *largest = *a;
        *second_largest = *(a + 1);
    } else {
        *largest = *(a + 1);
        *second_largest = *a;
    }

    for (p = a + 2; p < a + n; p++) {
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        } else if (*p > *second_largest) {
            *second_largest = *p;
        }
    }
}


int main(void)
{
    int n, largest, second_largest;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    find_two_largest(a, n, &largest, &second_largest);

    printf("%d %d\n", largest, second_largest);

    return 0;
}
