#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    int losses = 0, wins = 0;
    char play_again;
    bool outcome;
    srand((unsigned) time(NULL));

    while(true) {
        outcome = play_game();
        
        if(outcome) {
            wins++;
            printf("You win!\n");
        } else {
            losses++;
            printf("You lose!\n");
        }

        printf("Play again? ");
        scanf(" %c", &play_again);

        if (play_again != 'y' && play_again != 'Y') {
           break;
        }
    }
    printf("Wins: %d Losses: %d\n", wins, losses); 

    return 0;
}

int roll_dice(void) 
{
    int dice1, dice2;
    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;
    usleep(1e6);

    return dice1 + dice2;
}

bool play_game(void)
{
    int roll, point;

    roll = roll_dice();
    printf("You rolled: %d\n", roll); 
    switch (roll) {
        case 7: case 11:
            return true;
        case 2: case 3: case 12:
            return false;
    }

    point = roll;
    printf("Your point is %d\n", point);

    while (true) {
        roll = roll_dice();
        printf("You rolled: %d\n", roll);

        if (roll == point) {
            return true;
        } else if (roll == 7) {
            return false;
        }
    }
}
