#include <stdio.h>

#define N 5

int main(void)
{
    int m[N][N], i, j, high, low;
    long sum;

    for (i = 0; i < N; i++) {
        printf("Enter grades for quiz %d: ", i + 1);
        for (j = 0; j < N; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    printf("Quiz Avg. Score High Score Low Score\n");
    for (i = 0; i < N; i++) {
        sum = 0;
        high = low = m[i][0];
        for (j = 0; j < N; j++) {
            sum += m[i][j];
            if (m[i][j] < low) {
                low = m[i][j];
            }
            if (m[i][j] > high) {
                high = m[i][j];
            }
        }
        printf("%4d %10.2lf %10d %9d\n", i+1, sum/5.0, high, low);       
    }

    printf("Student Avg. Score Total Score\n");
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            sum += m[j][i];
        }
        printf("%7d %10.2lf %11ld\n", i+1, sum / 5.0, sum);
    }
    
    return 0;
}
