#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part* next;
};

struct part* first = NULL;

struct part* find_part(int part_number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);
int read_line(char* str, int n);

int main(void)
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);

        switch (code) {
        case 'i': insert();
            break;

        case 's': search();
            break;

        case 'u': update();
            break;

        case 'p': print();
            break;

        case 'e': erase();
            break;

        case 'q': return 0;
        }
        printf("\n");
    }
}

struct part* find_part(int part_number)
{
    struct part* p;

    for (p = first;
        p != NULL && part_number > p->number;
        p = p->next);

    if (p != NULL && p->number == part_number)
        return p;

    return NULL;
}

void insert(void)
{
    struct part* new_node, *prev, *curr;
    int number;

    printf("Enter part number: ");
    scanf("%d", &number);

    for (prev = NULL, curr = first;
        curr != NULL && number > curr->number;
        prev = curr, curr = curr->next);
    
    if (curr != NULL && number == curr->number) {
        printf("Part already present.\n");
        return;
    }

    new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        printf("Error: malloc failed in insert.\n");
        return;
    }

    new_node->number = number;
    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &(new_node->on_hand));

    if (prev == NULL) {
        new_node->next = first;
        first = new_node;
        return;
    }

    prev->next = new_node;
    new_node->next = curr;
}

void search(void)
{
    int number;
    struct part* p;

    printf("Enter part number: ");
    scanf("%d", &number);

    p = find_part(number);
    if (p == NULL) {
        printf("Part not found.\n");
        return;
    }

    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
}

void update(void)
{
    int number, change;
    struct part* p;

    printf("Enter part number: ");
    scanf("%d", &number);

    p = find_part(number);
    if (p == NULL) {
        printf("Part not found.\n");
        return;
    }

    printf("Enter the change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
}

void erase(void)
{
    int number;
    struct part* prev, * curr, * temp;

    printf("Enter part number: ");
    scanf("%d", &number);

    for (prev = NULL, curr = first;
        curr != NULL && number > curr->number;
        prev = curr, curr = curr->next);

    if (curr == NULL)
        return;

    if (prev == NULL) {
        first = first->next;
        free(curr);
        return;
    }

    prev->next = curr->next;
    free(curr);
}

void print(void)
{
    struct part* p;

    printf("Part Number Part Name        "
        "Quantity on Hand\n");
    for (p = first; p != NULL; p = p->next)
        printf("%-7d     %-25s%-11d\n", p->number, p->name, p->on_hand);
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