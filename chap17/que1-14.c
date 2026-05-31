#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void add_to_list(struct node** list, int n)
{
    struct node* new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list.\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

void delete_from_list(struct node** list, int n)
{
    struct node* prev, * curr;
    for (prev = NULL, curr = *list;
        curr != NULL && curr->value != n;
        prev = curr, curr = curr->next);

    if (curr == NULL)
        return;

    if (prev == NULL) {
        *list = (*list)->next;
        free(curr);
        return;
    }

    prev->next = curr->next;
    free(curr);
}

int main(void)
{
    struct node* first = NULL;
    struct node* p;
    add_to_list(&first, 18);
    add_to_list(&first, 27);
    add_to_list(&first, 20);
    add_to_list(&first, 81);
    add_to_list(&first, 64);

    for (p = first; p != NULL; p = p->next)
        printf(" %d", p->value);
    printf("\n");

    delete_from_list(&first, 64);

    for (p = first; p != NULL; p = p->next)
        printf(" %d", p->value);
    printf("\n");

    delete_from_list(&first, 18);

    for (p = first; p != NULL; p = p->next)
        printf(" %d", p->value);
    printf("\n");

    delete_from_list(&first, 20);

    for (p = first; p != NULL; p = p->next)
        printf(" %d", p->value);
    printf("\n");

    return 0;
}
