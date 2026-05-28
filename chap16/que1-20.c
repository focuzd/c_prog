#include <stdio.h>

int main(void)
{
    int x, y;
    enum { NORTH, SOUTH, EAST, WEST } direction;

    switch (direction) {
    case EAST: x++; break;
    case WEST: x--; break;
    case SOUTH: y++; break;
    case NORTH: y--; break;
    }
}