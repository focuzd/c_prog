#include <stdio.h>

int main(void)
{
    int n, i, j;
    long long int factorial;
    double e = 0;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Value should be greater 0");
    }

    for (i = 1; i <= n; i++) {
        factorial = 1;
        for (j = 1; j <= i; j++) {
            factorial *= j;
        } 
        e = e + (1.0 / factorial);
        printf("%lld %lf %lf\n", factorial,
                (1.0/ factorial), e);
    }
    
    printf("The value of series is %.3lf\n", e);
    return 0;
}
