#include <stdio.h>

int count_ones(unsigned char ch);

int main(void)
{
    unsigned char ch;
    for (ch = 1; ch; ch++)
        printf("%d %d\n", ch, count_ones(ch));
    return 0;
}

int count_ones(unsigned char ch)
{
    int count = 0;

    while (ch) {
        count++;
        ch &= ch - 1;
    }

    return count;
}