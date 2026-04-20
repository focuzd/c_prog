#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10

int data[STACK_SIZE];
int *top = data;

void make_empty(void)
{
    top = data;
}

bool is_empty(void)
{
    return (top == data);
}

bool is_full(void)
{
    return top == &data[STACK_SIZE];
}

int main(void)
{

    return 0;
}
