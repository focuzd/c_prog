#include <stdio.h>
#include <string.h>

int main(void)
{
    int c[10] = {5, 8, [4] = 6, 9, 7, [9] = 2};
    int a[5];
    printf("a: %d\nc: %d\n", a, c);

    memcpy(a, c, sizeof(c)); //intentional overflow
    for (int i = 0; i < 10; i++) {
        printf(" %d", c[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}
