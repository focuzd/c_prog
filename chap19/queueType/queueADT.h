#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

#define QUEUE_SIZE 100

typedef int Item;
typedef struct {
    Item contents[QUEUE_SIZE];
    int front, rear, num_items;
} Queue;

// Queue* create(void);
// void destroy(Queue* q);
void make_empty(Queue* q);
bool is_empty(Queue* q);
void enqueue(Queue* q, Item i);
void dequeue(Queue* q);
Item peek_front(Queue* q);
Item peek_rear(Queue* q);

#endif 