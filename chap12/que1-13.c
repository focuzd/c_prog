#include <stdio.h>

int main(void)
{
    int n, *p, i;
    scanf("%d", &n);

    int identity[n][n];
    
    for (i = 0, p = &identity[0][0]; p <= &identity[n-1][n-1];
            p++, i++) 
        if (i % (n+1) == 0)
            *p = 1;
        else
            *p = 0;

    for (i = 0, p = &identity[0][0]; p <= &identity[n-1][n-1];
            p++, i++) {
        printf(" %d", *p);
        if (i % n == n-1) 
            printf("\n");
    }

    return 0;
}        
