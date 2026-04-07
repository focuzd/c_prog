#include <stdio.h>

int main(void)
{
    float x, polynomial;

    printf("Enter the value of x: ");
    scanf("%f", &x);

    polynomial = (3*x*x*x*x*x) + (2*x*x*x*x) - (5*x*x*x) - (x*x) + (7*x) - 6;

    printf("Value of polynomial: %f\n", polynomial);

    return 0;
}
