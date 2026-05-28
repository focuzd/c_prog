#include <stdio.h>

#define PRINT_VAR(n) printf(#n ": %d\n", n)

int main(void) {
    struct { int x, y; } x;
    struct { int x, y; } y;

    x.x = 5;
    x.y = 6;
    y.x = 10;
    y.y = 11;

    PRINT_VAR(x.x);
    PRINT_VAR(x.y);
    PRINT_VAR(y.x);
    PRINT_VAR(y.y);

    return 0;
}