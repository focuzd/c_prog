#include <stdio.h>

int main(void)
{
    int array[10] = {0};
    int *arr = array;

    printf("sizeof(array): %zu\nsizeof(arr): %zu\n", sizeof(array), sizeof(arr));

    return 0;
}
