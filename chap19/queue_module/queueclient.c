#include <stdio.h>
#include "queue.h"

int main(void)
{
    make_empty();
    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("Front of queue: %d\n", peek_front());
    printf("Back of queue: %d\n", peek_rear());

    make_empty();

    if (is_empty())
        printf("Queue is empty\n");
    else
        printf("Queue is full\n");

    return 0;
}