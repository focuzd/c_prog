#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node* next;
};

struct node* top = NULL;

bool is_empty(void);
bool is_full(void);
void clear_stack(void);
void push(int x);
int pop(void);

int main(void)
{
    int x;
    clear_stack();

    for (;;) {
        scanf("%d", &x);
        if (x == 0)
            break;
        push(x);
    }

    while (!is_empty()) {
        x = pop();
        printf("%d\n", x);
    }
    x = pop();

    return 0;
}

bool is_full(void)
{
    struct node* temp = malloc(sizeof(*temp));
    bool res = (temp == NULL);
    free(temp);
    return res;
}

bool is_empty(void)
{
    return (top == NULL);
}

void clear_stack(void)
{
    struct node* p, * q;
    for (p = top; p != NULL; p = q) {
        q = p->next;
        free(p);
    }
    top = NULL;
}

void push(int x)
{
    if (is_full()) {
        printf("Stack is full.\n");
        exit(EXIT_FAILURE);
    }

    struct node* new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        printf("Error: Malloc failed in push.\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = x;
    new_node->next = top;
    top = new_node;
}

int pop(void)
{
    if (is_empty()) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct node* temp;
    int return_value;

    return_value = top->value;
    temp = top;
    top = top->next;
    free(temp);

    return return_value;
}