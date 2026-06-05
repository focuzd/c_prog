#include <stdio.h>
#include <stdlib.h>
#include "queueADT2.h"

struct queue_type {
    Item *contents;
    int front, rear, num_items, size;
};

static void terminate(const char* message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(int size)
{
    Queue q = malloc(sizeof(*q));
    if (q == NULL)
        terminate("Error in create: unable to create queue.");

    q->contents = malloc(size * sizeof(*(q->contents)));
    if (q->contents == NULL) {
        free(q);
        terminate("Error in create: unable to create queue.");
    }

    q->front = q->rear = q->num_items = 0;
    q->size = size;
    return q;
}

void destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void make_empty(Queue q)
{
    q->front = q->rear = q->num_items = 0;
}

bool is_empty(Queue q)
{
    return q->num_items == 0;
}

bool is_full(Queue q)
{
    return q->num_items == q->size;
}

void enqueue(Queue q, Item i)
{
    if (is_full(q))
        terminate("Error in enqueue: Queue is full.");

    q->contents[q->rear] = i;
    q->rear = (q->rear + 1) % q->size;
    q->num_items++;
}

void dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error in dequeue: Queue is empty");

    q->front = (q->front + 1) % q->size;
    q->num_items--;
}

Item peek_front(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek_front: Queue is empty.");

    return q->contents[q->front];
}

Item peek_rear(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek_rear: Queue is empty.");

    return q->contents[q->rear - 1];
}