#include <stdio.h>

int main(void)
{
    int n, i, j;
    long long int factorial;
    double e = 0, epsilon;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Enter the value of epsilon: ");
    scanf("%lf", &epsilon);

    if (n <= 0) {
        printf("Value should be greater 0");
    }

    for (i = 1; i <= n; i++) {
        factorial = 1;
        
        for (j = 1; j <= i; j++) {
            factorial *= j;
        } 

        if ( epsilon > (1.0 / factorial)) {
            printf("Stopping, %g > %g\n", epsilon, 
                    (1.0 / factorial)); 
            break;
        }

        e = e + (1.0 / factorial);
    }
    
    printf("The value of series is %g\n", e);
    return 0;
}
