#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void delete_list2(struct node** list, int n)
{
    struct node* p, * temp;


    p = *list;
    if (p->value == n) {
        *list = (*list)->next;
        free(p);
        return;
    }

    while (p->next != NULL && p->next->value != n)
        p = p->next;

    if (p->next == NULL)
        return;
    
    temp = p->next;
    p->next = p->next->next;
    free(temp);
}