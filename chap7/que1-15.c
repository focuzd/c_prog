#include <stdio.h>

int main(void) {
    typedef signed char Int8;
    typedef short Int16;
    typedef int Int32;
    
    printf("Size of defined types in bytes:\n");
    printf("Int8: %zu\n", sizeof(Int8));
    printf("Int16: %zu\n", sizeof(Int16));
    printf("Int32: %zu\n", sizeof(Int32));
    return 0;
}
