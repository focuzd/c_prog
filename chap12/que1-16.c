#include <stdio.h>

#define DAYS 7
#define HOURS 24

int find_largest(int a[], int n) 
{
    int *p, largest;

    largest = *a;
    for (p = a; p < a + n; p++) 
        if (*p > largest) 
            largest = *p;

    return largest;
}

int main(void)
{
    int temperatures[DAYS][HOURS] = {0};
    int i;
    
    temperatures[2][5] = 20;
    temperatures[3][15] = 19;
    temperatures[4][23] = 10;
    
    for (i = 0; i < DAYS; i++)
        printf("Day %d: %d\n", i + 1, 
                find_largest(temperatures[i], HOURS));

    return 0;
}
