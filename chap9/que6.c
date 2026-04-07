#include <stdio.h>

double polynomial(double x);

int main(void)
{
    double x;
    printf("Enter a number: ");
    scanf("%lf", &x);

    printf("Value of polynomial at %g is %g\n",
            x, polynomial(x));
    
    return 0;
}

double polynomial(double x) 
{
    return ((3*x*x*x*x*x) + (2*x*x*x*x) - (5*x*x*x) - (x*x) + (7*x) - 6);
}
