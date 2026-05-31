#include <stdio.h>
#include <stdlib.h>

int* create_array(int n, int initial_value)
{
    int i;

    int* a = malloc(n * sizeof(*a));
    if (a == NULL)
        return NULL;

    for (i = 0; i < n; i++)
        a[i] = initial_value;
    return a;
}

int main(void)
{
    int i, n = 8, initial_value = 56;
    int* a;
    a = create_array(n, initial_value);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    putchar('\n');

    return 0;
}