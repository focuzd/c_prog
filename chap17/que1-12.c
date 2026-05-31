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

struct node* find_last(struct node* list, int n)
{
    struct node* last = NULL;
    for (; list != NULL; list = list->next)
        if (list->value == n)
            last = list;

    return last;
}

int main(void)
{
    struct node* list = NULL;
    int x, n;

    for (;;) {
        scanf("%d", &x);
        if (x == 0)
            break;
        add_to_list(&list, x);
    }

    scanf("%d", &n);
    printf("%p\n", find_last(list, n));

    struct node* p = list;
    for (; p != NULL; p = p->next) {
        printf("%p %d\n", p, p->value);
    }

    return 0;
}