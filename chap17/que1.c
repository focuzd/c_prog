#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int find_part(struct part* inventory, int num_parts, int part_number);
void insert(struct part** inventory, int* num_parts, int *capcity);
void search(struct part* inventory, int num_parts);
void update(struct part* inventory, int num_parts);
void print(struct part* inventory, int num_parts);
int read_line(char* str, int n);

int main(void)
{
    struct part* inventory;
    int num_parts = 0;
    int capacity = 5;
    char code;

    inventory = malloc(capacity * sizeof(*inventory));
    if (inventory == NULL) {
        printf("Error: malloc failed in main.\n");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);

        switch (code) {
        case 'i': insert(&inventory, &num_parts, &capacity);
            break;

        case 's': search(inventory, num_parts);
            break;

        case 'u': update(inventory, num_parts);
            break;

        case 'p': print(inventory, num_parts);
            break;

        case 'q': return 0;
        }

        printf("\n");
    }
}

int find_part(struct part* inventory, int num_parts, int part_number)
{
    int i;
    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == part_number)
            return i;
    return -1;
}

void insert(struct part** inventory, int *num_parts, int *capacity)
{
    int number, i;

    if (*num_parts == *capacity) {
        *capacity *= 2;
        *inventory = realloc(*inventory, *capacity * sizeof(struct part));
        if (*inventory == NULL) {
            printf("--No space left--.\n");
            return;
        }
    }

    printf("Enter part number: ");
    scanf("%d", &number);

    if (find_part(*inventory, *num_parts, number) != -1) {
        printf("Part already present.\n");
        return;
    }

    (*inventory)[*num_parts].number = number;
    printf("Enter part name: ");
    read_line((*inventory)[*num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &(*inventory)[*num_parts].on_hand);
    (*num_parts)++;
}

void search(struct part* inventory, int num_parts)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);
    if (i == -1) {
        printf("Part not found.\n");
        return;
    }

    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
}

void update(struct part* inventory, int num_parts)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);
    if (i == -1) {
        printf("Part not found.\n");
        return;
    }

    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
}

void print(struct part* inventory, int num_parts)
{
    int i;

    printf("Part Number Part Name        "
        "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%-7d     %-25s%-11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

int read_line(char* str, int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()));

    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';

    return i;
}