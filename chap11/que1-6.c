#include <stdio.h>

void find_two_largest(int a[], int n, int *largest,
        int *second_largest);

int main(void)
{
    int n, i, largest, second_largest;
    scanf("%d", &n);
    
    int a[n];
    for (i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    find_two_largest(a, n, &largest, &second_largest);
    printf("largest: %d\nsecond largest: %d\n", largest,
            second_largest);

    return 0;
}

void find_two_largest(int a[], int n, int *largest,
        int *second_largest)
{
    int i;

    // *largest = *second_largest = a[0];
    // wont work if the first element is largest;

    if (a[0] > a[1]) {
        *largest = a[0];
        *second_largest = a[1];
    } else {
        *largest = a[1];
        *second_largest = a[0];
    }

    for (i = 2; i < n; i++) {
       if (a[i] > *largest) {
           *second_largest = *largest;
           *largest = a[i];
       } else if (a[i] > *second_largest) {
            *second_largest = a[i];
       }
       // after we find the largest element second largest will not
       // be upated, it will be the second largest element until
       // we found the largest, so we need to check if there are
       // elements greater than second largest but not greater than
       // largest
    }
}
