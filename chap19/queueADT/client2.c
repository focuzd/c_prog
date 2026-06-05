#include <stdio.h>
#include "queueADT2.h"

int main(void)
{
    Queue q1 = create(10), q2 = create(15);
    int n;

    make_empty(q1);
    make_empty(q2);

    enqueue(q1, 4);
    enqueue(q1, 5);
    enqueue(q1, 6);

    n = peek_front(q1);
    dequeue(q1);
    enqueue(q2, n);

    n = peek_front(q1);
    enqueue(q2, n);

    //make_empty(q1);
    if (is_empty(q1))
        printf("q1 is empty.\n");
    else
        printf("q1 is not empty\n");

    destroy(q1);

    while (!is_empty(q2)) {
        printf("front of q2: %d\n", peek_front(q2));
        printf("dequeue q2\n");
        dequeue(q2);
    }

    destroy(q2);

    return 0;
}