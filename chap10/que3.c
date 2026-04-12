#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

char hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

void read_cards(void)
{
    char ch, rank_ch, suit_ch;
    char valid_ranks[NUM_RANKS] = {'2', '3', '4', '5', '6',
        '7', '8', '9', 'j', 'q', 'k', 'a'};
    bool bad_card;
    int cards_read = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = tolower(getchar());
        
        if (rank_ch == '0') exit(EXIT_SUCCESS);
        for (i = 0; i < NUM_RANKS; i++)
            if (rank_ch == valid_ranks[i]) 
                break;
        
        if (i >= NUM_RANKS) bad_card = true;

        suit_ch = tolower(get_char());
        if (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's') {
            bad_card = true;
        }

        while ((ch = getchar()) != '\n') {
            if (ch != ' ') bad_card = true;
        }

        if (bad_card) {
            printf("Bad card; ignored.\n");
            continue;
        } 

        i = 0;
        while (i < cards_read) {
            if (hand[i][0] == rank_ch && hand[i][1] == suit_ch) {
                printf("Duplicate card; ignored.\n");
                break;
            }
        }

        if (i < cards_read) {
            hand[cards_read][0] = rank_ch;
            hand[cards_read][1] = suit_ch;
            cards_read++;
        }
    }
}

void analyze_hand(void)
{
    int num_consec = 0;
    int rank, suit;

    straight = flush = four = three = false;
    pairs = 0;

    for (suit = 0; suit < NUM_SUITS; suit++) {
        if (num_in_suit[suit] == NUM_CARDS) {
            flush = true;
        }
    }

    rank = 0;
    while (num_in_rank[rank] == 0) rank++;
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++) {
        num_consec++;
    }
    if (num_consec == NUM_CARDS) {
        straight = true;
        return;
    }

    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (num_in_rank[rank] == 4) four = true;
        if (num_in_rank[rank] == 3) three = true;
        if (num_in_rank[rank] == 2) pairs++;
    }
}

void print_result(void)
{
    if (straight && flush) printf("Straight flush");
    else if (four) printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush) printf("Flush");
    else if (straight) printf("Straight");
    else if (three) printf("Three of a kind");
    else if (pairs == 2) printf("Two pairs");
    else if (pairs == 1) printf("Pair");
    else printf("High card");

    printf("\n\n");
}


