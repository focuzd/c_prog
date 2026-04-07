#include <stdio.h>

int main(void)
{
    int n, i;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Enter a number greater than or equal to 1\n");
        return 1;
    }

    for (i = 2; i * i <= n; i += 2) {
        printf("%d\n", i*i);
    }

    return 0;
}
