#include <stdio.h>

int *find_middle(int *a, int n) {
    return a + n/2;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5, 6};

    printf("%d %d\n", *(find_middle(a, 5)), 
            *(find_middle(b, 6)));
    return 0;
}
