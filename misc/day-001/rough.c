#include <stdio.h>
#define PERROR 10e-6

int main(void)
{
    int n;
    scanf("%d", &n);
    double array[n];

    for (int i = 0; i < n; i++) {
        scanf("%lf", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        int temp = array[i];
        if (array[i] - temp > PERROR) {
            printf("%lf, Not an integer\n", array[i]);
        } else {
            printf("%lf, integer", array[i]);
        }
    }

    return 0;
}
