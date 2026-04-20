#include <stdio.h>
#include <stdbool.h>

#define HOURS 24
#define DAYS 7

void print_row(const int temperatures[DAYS][HOURS], int row) 
{
    const int *p;

    for (p = temperatures[row]; 
            p <= &temperatures[row][HOURS-1]; p++)
        printf(" %d", *p);

    printf("\n");
}

int main(void)
{
    int temperatures[DAYS][HOURS] = {0};

    temperatures[3][13] = 3;
    print_row(temperatures, 3);

    return 0;
}
