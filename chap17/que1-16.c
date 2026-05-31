#include <stdio.h>

int sum(int (*f)(int), int start, int end)
{
    int sum = 0;

    for (; start <= end; start++) {
        sum += (*f)(start);
    }

    return sum;
}

int f1(int x) {
    return 2 * x;
}

int main(void)
{
    printf("%d\n", sum(f1, 3, 8));

    return 0;
}