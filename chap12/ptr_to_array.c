#include <stdio.h>

#define N 10

int main(void)
{
    int a[N][N], (*p)[N];

    for (p = &a[0]; p < &a[N]; p++) {
        printf("%p(%zu) %p(%zu)\n", p, sizeof(p), *p, sizeof(*p));
    }
    // p is a pointer to array, sizeof (p) = size of a pointer variable
    // *p returns object p points to ie a[i]
    // *p is an array of 10 elements, therefore sizeof (*p) = 10 * sizeof(int)
    // we index an array not a pointer to an array, therefore we index (*p)
    
    return 0;
}
