#include <stdio.h>

int main(void)
{
    int num;
    const int segments[10][7] = {
        {1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1},
    };

    num = 0;
    while (num < 10) {
        if (segments[num][0]) printf(" __"); else printf("  ");
        printf("\n");
        if (segments[num][5]) printf("|"); else printf(" ");
        if (segments[num][6]) printf("__"); else printf("  ");
        if (segments[num][1]) printf("|"); else printf(" ");
        printf("\n");
        if (segments[num][4]) printf("|"); else printf(" ");
        if (segments[num][3]) printf("__"); else printf("  ");
        if (segments[num][2]) printf("|"); else printf(" ");
        printf("\n");
        num++;
    }

    return 0;
}
