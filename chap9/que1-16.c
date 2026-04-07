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
    return (n == 0) ? 1 : n * fact(n - 1);
}
