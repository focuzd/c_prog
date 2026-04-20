#include <stdio.h>
#include <stdbool.h>

#define HOURS 24
#define DAYS 7

bool search(const int temperatures[DAYS][HOURS]) 
{
    const int *p;

    for (p = temperatures[0]; 
            p <= &temperatures[DAYS-1][HOURS-1]; p++)
        if (*p == 32) return true;

    return false;
}

int main(void)
{
    int temperatures[DAYS][HOURS] = {0};

    temperatures[3][13] = 3;
    if (search(temperatures)) 
        printf("Found\n");
    else 
        printf("Not Found\n");

    return 0;
}
