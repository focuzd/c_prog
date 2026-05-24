#include <stdio.h>

#define ERROR(...) fprintf(stderr, __VA_ARGS__)

int main(void)
{
    int index = 5;
    ERROR("Range error: index = %d\n", index);

    return 0;
}