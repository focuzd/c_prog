#include <stdio.h>

int avg(int a, int b) {
    return (a + b) / 2;
}

int main(void)
{
    int i;
    double x;
    i = avg(3, 9);
    printf("%d\n", i);
    x = avg(3, 9);
    printf("%lf\n", x);
    i = avg(3.1, 9.2);
    printf("%d\n", i);
    x = avg(3.1, 9.2);
    printf("%lf\n", x);
    avg(3.1, 9.2);
}
