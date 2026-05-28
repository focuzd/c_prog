#include <stdio.h>

#define NUM_PEICES 6

enum chess_peices { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

const int peice_value[NUM_PEICES] = { 200, 9, 5, 3, 3, 1 };
const int peice_value1[NUM_PEICES] = { [KING] = 200, [QUEEN] = 9, [ROOK] = 5, [BISHOP] = 3,[KNIGHT] = 3, [PAWN] = 1 };
