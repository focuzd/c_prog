#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define COUNT_DIR 4

int main(void)
{
    int i, j, x1, y1, x, y, dir;
    char m[N][N], w = 'A';

    srand((unsigned) time(NULL));
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = '.';
        }
    }

    x = rand() % N;
    y = rand() % N;
    m[x][y] = w;
    w++;
    while (w != 'Z' + 1) {
        x1 = x;
        y1 = y;

        if (m[x+1][y] != '.' && m[x-1][y] != '.' && m[x][y+1] != '.' && m[x][y-1] != '.') 
            break;
        
        dir = rand() % COUNT_DIR;
        if (dir == 0) {
            x1 += 1;
        } else if (dir == 1) {
            x1 -= 1;
        } else if (dir == 2) {
            y1 += 1;
        } else {
            y1 -= 1;
        }

        if (m[x1][y1] == '.' && (x1 < N && x1 >= 0) && (y1 < N && y1 >= 0)) {
            x = x1;
            y = y1;
            m[x][y] = w;
            w++;
        } else {
            continue;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf(" %c", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
