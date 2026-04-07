#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define COUNT_DIR 4

void generate_random_walk(char walk[N][N]);
void print_array(char walk[N][N]);

int main(void)
{
    char walk[N][N];

    generate_random_walk(walk);
    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[N][N])
{
    int i, j, x, y, x1, y1, dir;
    char w = 'A';
    srand((unsigned) time(NULL));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            walk[i][j] = '.';
        }
    }

    x = rand() % N;
    y = rand() % N;
    walk[x][y] = w++;

    while (w <= 'Z') {
        x1 = x;
        y1 = y;
        
        if (walk[x+1][y] != '.' && walk[x-1][y] != '.' && walk[x][y+1] != '.' && walk[x][y-1] != '.') {
            break;
        }

        dir = rand() % COUNT_DIR;
        switch (dir) {
            case 0: y1++; break;
            case 1: x1++; break;
            case 2: y1--; break;
            case 3: x1--; break;
        }

        if ((walk[x1][y1] == '.') && (x1 < N && x1 >= 0) && (y1 < N && y1 >= 0)) {
                x = x1; 
                y = y1;
                walk[x][y] = w++;
        } else {
            continue;
        }
    }
}

void print_array(char walk[N][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf(" %c", walk[i][j]);
        }
        printf("\n");
    }
}
