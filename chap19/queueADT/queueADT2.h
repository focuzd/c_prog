#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type* Queue;
typedef int Item;

Queue create(int size);
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void enqueue(Queue q, Item i);
void dequeue(Queue q);
Item peek_front(Queue q);
Item peek_rear(Queue q);

#endif