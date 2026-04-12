#include <stdio.h>

int main(void)
{
    int i, *p;
    i = 10;
    p = &i;

    printf("%p %p\n", *&p, &i);
    printf("%p\n", &*p); 
    // here the value is same as p, which mean indirection operator, gives the object a pointer points to 
    // not the value of the object, &(*p) = &i = p 

    return 0;
}
