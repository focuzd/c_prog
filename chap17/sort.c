#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int compare_parts(const void* p, const void* q) {
    return ((struct part*)p)->number - ((struct part*)q)->number;
}

void print(struct part inventory[], int num_parts)
{
    int i;

    printf("Part Number Part Name        "
        "Quantity on Hand Price per unit\n");
    for (i = 0; i < num_parts; i++)
        printf("%-7d     %-25s%-11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

int main(void)
{
    struct part inventory[50];
    int num_parts = 4;

    inventory[0] = (struct part){ 528, "Printer Cable", 7 };
    inventory[1] = (struct part){ 119, "Laptop Charger", 2 };
    inventory[2] = (struct part){ 914, "Mouse", 7 };
    inventory[3] = (struct part){ 100, "Battery", 15 };
    qsort(inventory, num_parts, sizeof(struct part), compare_parts);
    print(inventory, num_parts);
}