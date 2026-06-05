#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 100

static Item contents[QUEUE_SIZE];
static int front = 0, rear = 0, num_items = 0;

static void terminate(const char* message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    front = rear = num_items = 0;
}

bool is_empty(void)
{
    return num_items == 0;
}

static bool is_full(void)
{
    return num_items == QUEUE_SIZE;
}


void enqueue(const Item i)
{
    if (is_full())
        terminate("Error in enqueue: Queue is full.");

    contents[rear] = i;
    rear = (rear + 1) % QUEUE_SIZE;
    num_items++;
}

void dequeue(void)
{
    Item return_val;
    if (is_empty())
        terminate("Error in dequeue: Queue is empty.");

    front = (front + 1) % QUEUE_SIZE;
    num_items--;
}

Item peek_front()
{
    if (is_empty())
        terminate("Error in peek_front: Queue is empty.");
    
    return contents[front];
}

Item peek_rear()
{
    if (is_empty())
        terminate("Error in peek_rear: Queue is empty.");
    
    return contents[rear-1];
}