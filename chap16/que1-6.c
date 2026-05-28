#include <stdio.h>

struct time {
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds)
{
    struct time t;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600;

    t.minutes = total_seconds / 60;
    total_seconds %= 60;

    t.seconds = total_seconds;

    return t;
}

int main(void)
{
    long total_seconds = 84000;
    struct time t = split_time(total_seconds);

    printf("hours: %d\nminutes: %d\nseconds: %d\n",
        t.hours, t.minutes, t.seconds);

    return 0;
}