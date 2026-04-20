#include <stdio.h>
#include <stdbool.h>

bool search(const int a[], int n, int key)
{
    const int *p;

    for (p = a; p < a + n; p++) 
        if (key == *p) return true;

    return false;
}

int main(void)
{
    int n, key, i;
    scanf("%d %d", &n, &key);
    
    int a[n];
    for (i = 0; i < n; i++) 
        scanf("%d", a + i);

    bool found = search(a, n, key);
    if (found)
        printf("Found\n");
    else
        printf("Not found\n");

    return 0;
}
