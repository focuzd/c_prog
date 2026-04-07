#include <stdio.h>

int gcd(int m, int n);

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    
    printf("%d\n", gcd(m, n));

    return 0;
}

int gcd(int m, int n)
{
    if (n == 0) return m;
    gcd(n, m % n);
}
