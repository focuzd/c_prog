#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
    int i, a[N];

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, N-1);
    printf("In sorted order: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int a[], int low, int high)
{
    int partition_idx;
    if (low >= high) {
        return;
    }

    partition_idx = split(a, low, high);
    quicksort(a, low, partition_idx - 1);
    quicksort(a, partition_idx + 1, high);
}

int split(int a[], int low, int high)
{
        int pivot = a[low];

        for (;;) {
            while (low < high && a[high] >= pivot) {
                high--;
            }
            if (low >= high) break;
            a[low] = a[high];
            low++;
            
            while (low < high && a[low] < pivot) {
                low++;
            }
            if (low >= high) break;
            a[high] = a[low];
            high--;
        }
        
        a[high] = pivot;
        return high;
}
