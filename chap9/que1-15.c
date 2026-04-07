#include <stdio.h>

double median(double x, double y, double z);

int main(void)
{   
    double x, y, z;
    scanf("%lf%lf%lf", &x, &y, &z);

    printf("%g\n", median(x, y, z));

    return 0;
}

double median(double x, double y, double z)
{
    double temp;
    if (x > y) {
        temp = x; x = y; y = temp;
    }
    if (y > z) {
        temp = y; y = z; z = temp;
    }
    if (x > y) {
        temp = x; x = y; y = temp;
    }

    return y;
}
