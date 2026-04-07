#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    label: printf("Hello\n");

    if (num > 0) {
        num--;
        goto label;
    }

    return 0;
}
