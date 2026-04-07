#include <stdio.h>

int main(void)
{
    int n, x, y, i, j, x1, y1;
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    scanf("%d", &n);

    int m[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }

    y = (n - 1) / 2;
    x = 0;
    m[x][y] = 1; 
    
    for (i = 2; i <= n*n; i++) {
        x1 = (n + x - 1) % n;
        y1 = (y + 1) % n;

        if (m[x1][y1] == 0) {
            m[x1][y1] = i;
        } else {
            x1 = (x + 1) % n;
            y1 = y;
            m[x1][y1] = i;
        }
    
        x = x1;
        y = y1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
