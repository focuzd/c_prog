#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

void make_empty(void);
void enqueue(const Item i);
void dequeue(void);
Item peek_front(void);
Item peek_rear(void);
bool is_empty(void);

#endif 