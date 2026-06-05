#include <stdio.h>
#include "stackADT2.h"

int main(void)
{
    Stack s1, s2;
    int n;

    s1 = create(2);
    s2 = create(5);

    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    push(s1, 6);

    printf("Top of s1: %d\n", peek(s1));

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    push(s2, n);
    n = pop(s1);
    printf("Popped %d from s1\n", n);
    push(s2, n);

    destroy(s1);

    printf("Top of s2: %d\n", peek(s2));

    while (!is_empty(s2))
        printf("Popped %d from s2\n", pop(s2));

    push(s2, 3);
    make_empty(s2);
    if (is_empty(s2))
        printf("s2 is empty.\n");
    else
        printf("s2 isn't empty.\n");

    destroy(s2);

    return 0;
}