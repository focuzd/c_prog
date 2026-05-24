#include <stdio.h>

#define PRINT_CSTD printf("C standard: %ld\n", __STDC_VERSION__) 

int main(void)
{
    PRINT_CSTD;
    return 0;
}
