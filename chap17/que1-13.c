#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* insert_into_ordered_list(struct node* list, struct node* new_node)
{
    struct node* cur = list, * prev = NULL;

    if (new_node == NULL) {
        printf("Error: new_node is NULL.\n");
        return list;
    }

    while (cur != NULL && cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        new_node->next = cur;
        return new_node;
    }

    prev->next = new_node;
    new_node->next = cur;
    return list;
}