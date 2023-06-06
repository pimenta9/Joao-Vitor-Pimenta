#include <stdlib.h>
#include <stdio.h>
#include "maxHeap.h"

int* create_minHeap()
{
    int* heap = (int*) malloc(sizeof(int));
    if (heap == NULL) printf("ERROR!");
    heap[0] = -1;

    return heap;
}

int* minHeap_insert(int* heap, int heapSize, int x)
{
    heap = (int*) realloc(heap, (heapSize+2)*sizeof(int));

    heap[heapSize + 1] = x;

    int i = heapSize + 1;

    while (i > 1)
    {
        if (heap[i] < heap[i/2])
        {
            swap(heap, i, (i/2));
            i = i/2;
        }
        else
            return heap;
    }
    return heap;
}

void swap(int* heap, int i, int j)
{
    heap[i] = heap[i] + heap[j];
    heap[j] = heap[i] - heap[j];
    heap[i] = heap[i] - heap[j];
}

int* minHeap_delete(int* heap, int heapSize)
{
    int temp = heap[1];
    heap[1] = heap[heapSize];
    heap[heapSize] = temp;

    heap = (int*) realloc(heap, heapSize*sizeof(int));
    heapSize = heapSize - 1;

    int i = 1;
    while (i*2 <= (heapSize))
    {
        if ((i*2 + 1) <= heapSize)
        {
            if (heap[i] > heap[i*2] || heap[i] > heap[i*2 + 1])
            {
                if (heap[i*2] < heap[i*2 + 1])
                {
                    swap(heap, i, (i*2));
                    i = (i*2);
                }
                else
                {
                    swap(heap, i, (i*2 + 1));
                    i = (i*2 + 1);
                }
            }
            else
                return heap;
        }
        else
            if (heap[i] > heap[i*2])
                swap(heap, i, (i*2));
            else
                return heap;
    }

    return heap;
}
