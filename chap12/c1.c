#include <stdio.h>

int main(void)
{
    //hypothesis - a pointer to array of length m, is assigned a address of array of length n
    // for n > m, we should be able to traverse complete array since the array has valid memory

    int n = 10, m = 6, i;
    int a[n], (*p)[m];
    p = &a;
    // &a returns a pointer to the complete array and not same as &a[0]
    
    for (i = 0; i < n; i++) {
        (*p)[i] = i;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", (*p)[i]);
    }
    printf("\n");

    return 0;
}
