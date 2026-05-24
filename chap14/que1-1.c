#include <stdio.h>

#define CUBE(x) ((x)*(x)*(x))
#define MODULO_4(n) ((n) % 4)
#define PRODUCT(x, y) (((x)*(y) < 100) ? 1 : 0)

/*
a. works with integers and floating point values but will fail if x is not a numeric value and also can cause overflow depending on type of x

b. works with integers and characters, fails for floating point and other non numeric types

c. works for integers, characters, floating point values but will fail for non numeric types and has a chance of overflow
*/

int main(void)
{
    printf("%d\n", CUBE(10000));
    printf("%d\n", MODULO_4(27));
    printf("%d\n", PRODUCT(5, 8));

    return 0;
}