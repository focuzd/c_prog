#include <stdio.h>

#define CHECK(x, y, n) (((0 <= (x) && (x) < (n)) && (0 <= (y) && (y) < (n))) ? 1 : 0)

#define MEDIAN(x, y, z) (((x) > (y)) \
? (((x) > (z)) \
    ? (((y) > (z)) ? (y) : (z)) \
    : (x)) \
: (((y) > (z)) \
    ? (((x) > (z)) ? (x) : (z)) \
    : (y)))

#define POLYNOMIAL(x) ((3*(x)*(x)*(x)*(x)*(x)) + (2*(x)*(x)*(x)*(x)) - (5*(x)*(x)*(x)) - ((x)*(x)) + (7*(x)) - 6)


int main(void)
{
    printf("%d\n%d\n%d\n", CHECK(3, 5, 5), MEDIAN(1, 9, 7), POLYNOMIAL(1));

    return 0;
}