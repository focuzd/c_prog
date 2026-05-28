#include <stdio.h>
#include "readline.h"

#define MAX_PARTS 100
#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

int find_part(struct part inventory[], int num_parts, int number);
void insert(struct part inventory[], int* num_parts);
void search(struct part inventory[], int num_parts);
void update_qty(struct part inventory[], int num_parts);
void update_price(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);

int main(void)
{
    char code;
    struct part inventory[MAX_PARTS];
    int num_parts = 0;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);

        while (getchar() != '\n');

        switch (code) {
        case 'i': insert(inventory, &num_parts);
            break;

        case 's': search(inventory, num_parts);
            break;

        case 'u': update_qty(inventory, num_parts);
            break;

        case 'm': update_price(inventory, num_parts);
            break;

        case 'p': print(inventory, num_parts);
            break;

        case 'q': return 0;

        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(struct part inventory[], int num_parts, int number)
{
    int i;

    for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number)
            return i;
    }

    return -1;
}

void insert(struct part inventory[], int *num_parts)
{
    int part_number, i, j;

    if (part_number == MAX_PARTS) {
        printf("Database is full; can't add more part");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(inventory, *num_parts, part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    for (i = 0; i < *num_parts; i++) 
        if (part_number < inventory[i].number)
            break;

    for (j = *num_parts; j > i; j--)
        inventory[j] = inventory[j - 1];

    inventory[i].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[i].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[i].on_hand);
    printf("Enter price per unit: ");
    scanf("%lf", &inventory[i].price);

    (*num_parts)++;
}

void search(struct part inventory[], int num_parts)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);

    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price per unit: %g\n", inventory[i].price);
    }
    else
        printf("Part not found.\n");
}

void update_qty(struct part inventory[], int num_parts)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);

    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
        printf("Part not found.\n");
}

void update_price(struct part inventory[], int num_parts)
{
    int i, number;
    double change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);

    if (i >= 0) {
        printf("Enter change in price per unit: ");
        scanf("%lf", &change);
        inventory[i].price += change;
    }
    else
        printf("Part not found.\n");
}

void print(struct part inventory[], int num_parts)
{
    int i;

    printf("Part Number Part Name        "
        "Quantity on Hand Price per unit\n");
    for (i = 0; i < num_parts; i++)
        printf("%-7d     %-25s%-11d%-10g\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
}