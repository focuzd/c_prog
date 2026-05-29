#include <stdio.h>
#include <math.h>

void tabulate(double (*f) (double), double first, double last, double incr);

int main(void)
{
    double initial, final, incr;

    printf("Enter initial value: ");
    scanf("%lf", &initial);

    printf("Enter final value: ");
    scanf("%lf", &final);

    printf("Enter increment: ");
    scanf("%lf", &incr);

    printf("\n \tx \tcos(x)\n");
    printf("\t-------     -------\n");
    tabulate(cos, initial, final, incr);

    printf("\n \tx \tsin(x)\n");
    printf("\t-------     -------\n");
    tabulate(sin, initial, final, incr);


    printf("\n \tx \ttan(x)\n");
    printf("\t-------     -------\n");
    tabulate(tan, initial, final, incr);

    return 0;
}

void tabulate(double (*f) (double), double first, double last, double incr)
{
    double x;

    for (x = first; x < last; x += incr) 
        printf("%8g\t%8g\n", x, (*f)(x));

    printf("%8g\t%8g\n", last, (*f)(last));
}