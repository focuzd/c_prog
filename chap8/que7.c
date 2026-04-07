#include <stdio.h>

#define N 5

int main(void)
{
    int m[N][N], i, j;
    long sum;

    for (i = 0; i < N; i++) {
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < N; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    printf("\nRow totals:");
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            sum += m[i][j];
        }
        printf(" %ld", sum);
    }
    printf("\n");

    printf("Column totals:");
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            sum += m[j][i];
        }
        printf(" %ld", sum);
    }
    printf("\n");

    return 0;
}
