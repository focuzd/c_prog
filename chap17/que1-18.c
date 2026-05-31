#include <stdio.h>
#include <stdlib.h>

struct part {
    int number;
    char name;
    int on_hand;
};

int compare_parts(const void* p, const void* q)
{
    return ((struct part*)q)->number - ((struct part*)p)->number;
}

int main(void)
{
    struct part inventory[4] = {
        {234, 'a', 8},
        {914, 'b', 4},
        {328, 'c', 5},
        {500, 'q', 7}
    };

    qsort(inventory, 4, sizeof(struct part), compare_parts);
    for (int i = 0; i < 4; i++) 
        printf("%d\n", inventory[i].number);

    return 0;
}