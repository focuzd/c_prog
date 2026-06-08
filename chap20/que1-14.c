#include <stdio.h>

struct float_view {
    unsigned int fraction : 23, exponent : 8, sign : 1;
};

union fw {
    float val;
    struct {
        unsigned int fraction : 23, exponent : 8, sign : 1;
    } p;
};

// signed bit is most significant the and x86 follows little endian format 
// hence the order

int main(void)
{
    union fw f1;
    f1.val = -3.25;

    printf("%e\n", f1.val);
    printf("fraction: %u\nexponent: %u\nsign: %u\n", f1.p.fraction, f1.p.exponent, f1.p.sign);

    return 0;
}