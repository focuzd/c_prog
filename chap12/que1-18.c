#include <stdio.h>
#include <ctype.h>

int evaluate_position(const char board[8][8]);

int main(void)
{
    int i, j;
    char board[8][8];
    char *p;
    
    for (p = board[0]; p <= &board[7][7]; p++)
        *p = '.';

    board[0][0] = 'Q';
    board[6][5] = 'N';
    board[1][1] = 'b';
    board[2][7] = 'r';
    printf("%d\n", evaluate_position(board));

    return 0;
}

int evaluate_position(const char board[8][8]) 
{
    int w_sum = 0, b_sum = 0, val;
    const char *p;

    for (p = board[0]; p <= &board[7][7]; p++) {
        val = 0;
        switch(toupper(*p)) {
            case 'Q': val = 9; break;
            case 'R': val = 5; break;
            case 'B': case 'N':
                val = 3; break;
            case 'P': val = 1; break;
        }

        if (isupper(*p)) 
            w_sum += val;
        else 
            b_sum += val;
    }

    return (w_sum - b_sum);
}

