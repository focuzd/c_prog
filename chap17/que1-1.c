#include <stdio.h>
#include <stdlib.h>

void* my_malloc(size_t size)
{
    void* p = malloc(size);
    if (p == NULL) {
        printf("Error: malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

int main(void)
{
    unsigned long count = 100;
    int* arr = my_malloc(count * sizeof(*arr));
    free(arr);

    return 0;
}