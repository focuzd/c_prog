#include <stdio.h>

double inner_product(double a[], double b[], int n);

int main(void)
{
    double a[] = {5.3, 2.5, 3.71, 9.32};
    double b[] = {6.1, 4.67, 8.12, 7.04};

    int n = 4;
    printf("%g\n", inner_product(a, b, n));

    return 0;
}

double inner_product(double a[], double b[], int n)
{
    int i;
    double val = 0;
    
    for (i = 0; i < n; i++) {
        val += a[i]*b[i];        
    }

    return val;
}
