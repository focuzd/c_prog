#include <stdio.h>

int main(void)
{
    enum suits { CLUB, DIAMOND, HEART, SPADE };
    enum suits s1 = SPADE;
    enum suits s2 = 7;

    printf("%d\n%d\n", s1, s2);
    return 0;
}