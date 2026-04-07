#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
    int n;
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    scanf("%d", &n);

    int m[n][n];
    create_magic_square(n, m);
    print_magic_square(n, m);
    
    return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
    int i, j, x, y, x1, y1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            magic_square[i][j] = 0;
        }
    }

    x = 0;
    y = (n - 1) / 2;
    magic_square[x][y] = 1;

    for (i = 2; i <= n * n; i++) {
        x1 = (n + x - 1) % n;
        y1 = (y + 1) % n;

        if (magic_square[x1][y1] == 0) {
            magic_square[x1][y1] = i;
        } else {
            x1 = (x + 1) % n;
            y1 = y;
            magic_square[x1][y1] = i;
        }

        x = x1;
        y = y1;
    }
}

void print_magic_square(int n, int magic_square[n][n])
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", magic_square[i][j]);
        }
        printf("\n");
    }
}
