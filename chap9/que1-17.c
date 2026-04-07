#include <stdio.h>

long int fact(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%ld\n", fact(n));
    
    return 0;
}

long int fact(int n) 
{
    int i;
    long int product = 1;

    for (i = 1; i <= n; i++) {
        product *= i;
    }

    return product;
}
