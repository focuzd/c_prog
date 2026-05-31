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

int count_occurences(struct node* list, int n)
{
    int count = 0;

    while (list != NULL) {
        if (list->value == n)
            count++;
        list = list->next;
    }

    return count;
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
    printf("%d\n", count_occurences(list, n));

    return 0;
}