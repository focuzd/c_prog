#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
    Item data;
    struct node* next;
};

struct queue_type {
    struct node* front, *rear;
};

static void terminate(const char* message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(*q));
    if (q == NULL)
        terminate("Error in create: unable to create queue.");

    q->front = q->rear = NULL;
    return q;
}

void destroy(Queue q)
{
    make_empty(q);
    free(q);
}

void make_empty(Queue q)
{
    while (!is_empty(q))
        dequeue(q);
}

bool is_empty(Queue q)
{
    return (q->front == NULL);
}

bool is_full(Queue q)
{
    return false;
}

void enqueue(Queue q, Item i)
{
    struct node* new_node = malloc(sizeof(*new_node));
    if (new_node == NULL)
        terminate("Error in queue: Queue is full");

    new_node->data = i;
    new_node->next = NULL;
    if (is_empty(q))
        q->front = q->rear = new_node;
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

void dequeue(Queue q)
{
    struct node* old_front;
    if (is_empty(q))
        terminate("Error in dequeue: Queue is empty.");

    old_front = q->front;
    q->front = q->front->next;
    if (old_front == q->rear)
        q->rear == NULL;
    free(old_front);
}

Item peek_front(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek_front: Queue is empty.");

    return q->front->data;
}

Item peek_rear(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek_rear: Queue is empty.");

    return q->rear->data;
}