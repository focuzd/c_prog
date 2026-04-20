#include <stdio.h>

double inner_product(const double *a, const double *b, int n)
{
    const double *p, *q;
    double inner_prod;

    inner_prod = 0;
    for (p = a, q = b; p < a + n; p++, q++)
        inner_prod += (*p * *q);

    return inner_prod;
}

int main(void)
{
    double a[] = {5, 3.4, 6.3, 9.1};
    double b[] = {0, 1, 1, 0};

    double product = inner_product(a, b, 4);
    printf("%lf\n", product);

    return 0;
}
