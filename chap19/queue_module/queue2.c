#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
    Item data;
    struct node* next;
};

static struct node* front = NULL, * rear = NULL;

static void terminate(const char* message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    while (!is_empty())
        dequeue();
}

bool is_empty(void)
{
    return (front == NULL);
}

void enqueue(Item i)
{
    struct node* new_node = malloc(sizeof(*new_node));
    if (new_node == NULL)
        terminate("Error in enqueue: Queue is full.");

    new_node->data = i;
    new_node->next = NULL;

    if (is_empty())
        front = rear = new_node;
    else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(void)
{
    struct node* old_front;
    if (is_empty())
        terminate("Error in dequeue: Queue is empty.");

    old_front = front;
    front = front->next;
    if (old_front == rear)
        rear = NULL;
    
    free(old_front);
}

Item peek_front(void)
{
    if (is_empty())
        terminate("Error in peek_front: Queue is empty");

    return front->data;
}

Item peek_rear(void)
{
    if (is_empty())
        terminate("Error in peek_rear: Queue in empty");

    return rear->data;
}