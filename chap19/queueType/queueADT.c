#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

static void terminate(const char* message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

// Queue* create(void)
// {
//     Queue* q = malloc(sizeof(*q));
//     if (q == NULL)
//         terminate("Error in create: unable to create queue.");
    
// }

void make_empty(Queue* q)
{
    q->front = q->rear = q->num_items = 0;
}

bool is_empty(Queue* q)
{
    return q->num_items == 0;
}

bool is_full(Queue* q)
{
    return q->num_items == QUEUE_SIZE;
}

void enqueue(Queue* q, Item i)
{
    if (is_full(q))
        terminate("Error in enqueue: Queue is full");

    q->contents[q->rear] = i;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->num_items++;
}

void dequeue(Queue* q)
{
    if (is_empty(q))
        terminate("Error in dequeue: Queue is empty");

    q->front = (q->front + 1) % QUEUE_SIZE;
    q->num_items--;
}

Item peek_front(Queue* q)
{
    if (is_empty(q))
        terminate("Error in dequeue: Queue is empty");

    return q->contents[q->front];
}

Item peek_rear(Queue* q)
{
    if (is_empty(q))
        terminate("Error in dequeue: Queue is empty");

    return q->contents[q->rear - 1];
}