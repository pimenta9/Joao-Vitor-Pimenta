#include <stdio.h>
#include "maxHeap.h"

int main ()
{
    int* heap = create_maxHeap();
    int n = 0;
    int x;
    scanf("%d", &x);
    while (x)
    {
        heap = maxHeap_insert(heap, n, x);
        n++;
        scanf("%d", &x);
    }

    for (int i = 1; i < n+1; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    for (int i = 1; i < 3; i++)
    {
        printf("%d ", heap[i]);
        heap = maxHeap_delete(heap, n);
    }
    printf("\n");
    
    return 0;
}
