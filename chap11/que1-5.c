#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void)
{
    long total_sec;
    int hr, min, sec;
    scanf("%ld", &total_sec);

    split_time(total_sec, &hr, &min, &sec);
    printf("hr: %d\nmin: %d\nsec: %d\n", hr, min, sec);

    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / (60*60);
    total_sec %= 3600;

    *min = total_sec / 60;
    total_sec %= 60;

    *sec = total_sec;
}
