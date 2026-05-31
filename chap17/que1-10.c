#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

void print_part(struct part* p) {
    printf("Part number: %d\n", p->number);
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
}

int main(void)
{
    struct part p1 = { 528, "Printer Cable", 8 };
    print_part(&p1);

    return 0;
}