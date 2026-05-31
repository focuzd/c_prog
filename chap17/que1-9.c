#include <stdio.h>

struct point {
    int x, y;
};

int main(void)
{
    struct point p1 = { 4, 5 };
    if ((&p1)->x == p1.x)
        printf("True.\n");
    else
        printf("False.\n");

    return 0;
}