#include <stdio.h>

double power(double x, int n);

int main(void)
{
    double x;
    int n;
    
    printf("Enter a number: ");
    scanf("%lf", &x);
    printf("Enter the power: ");
    scanf("%d", &n);

    printf("%g ^ %d: %g\n", x, n, power(x, n));

    return 0;
}

double power(double x, int n) {
    if (n == 1) return x;

    if (n % 2 == 0) {
        return power(x, n/2) * power(x, n/2);
    }

    return x * power(x, n-1);
}
