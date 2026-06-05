#include <stdio.h>
#include "que4.h"

int main(void)
{
    Stack s1, s2;
    char* n;

    s1 = create();
    s2 = create();

    push(s1, "hello");
    push(s1, "world");

    printf("Top of s1: %s\n", (char *)peek(s1));

    n = pop(s1);
    printf("Popped %s from s1\n", n);
    push(s2, n);
    n = pop(s1);
    printf("Popped %s from s1\n", n);
    push(s2, n);

    destroy(s1);

    printf("Top of s2: %s\n", (char *)peek(s2));

    while (!is_empty(s2))
        printf("Popped %s from s2\n", (char *)pop(s2));

    push(s2, "from");
    make_empty(s2);
    if (is_empty(s2))
        printf("s2 is empty.\n");
    else
        printf("s2 isn't empty.\n");

    destroy(s2);

    return 0;
}