#include <stdio.h>
#include <stdlib.h>

typedef struct dragon
{
    int days;
    int fine;
} Dragon;

typedef struct Priority_queue
{
    Dragon dragon;
    struct Priority_queue* next;
} priority_queue;

Dragon make_dragon (int x, int y)
{
    Dragon dragon;
    dragon.days = x;
    dragon.fine = y;
    return dragon;
}

Dragon* create_minHeap()
{
    Dragon* heap = malloc(sizeof(Dragon));
    if (heap == NULL) printf("ERROR!");
    heap[0].days = -1;
    heap[0].fine = -1;

    return heap;
}

void swap(Dragon* heap, int i, int j)
{
    Dragon temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

Dragon* minHeap_insert(Dragon* heap, int heapSize, Dragon x)
{
    heap = realloc(heap, (heapSize+2)*sizeof(Dragon));
    if (!heap) printf("ERROR\n");

    heap[heapSize + 1] = x;

    int i = heapSize + 1;
    // printf("%d\n", i);

    while (i > 1)
    {
        // printf("heap[i].days = %d\nheap[i].fine = %d\n", heap[i].days, heap[i].fine);
        // printf("%lf\n%lf\n", (double) heap[i].days/heap[i].fine, (double) heap[i/2].days/heap[i/2].fine);
        if ((double) heap[i].days/heap[i].fine < (double) heap[i/2].days/heap[i/2].fine)
        {
            swap(heap, i, (i/2));
            i = i/2;
        }
        else
            return heap;
    }
    return heap;
}

Dragon* minHeap_delete(Dragon* heap, int heapSize)
{
    Dragon temp = heap[1];
    heap[1] = heap[heapSize];
    heap[heapSize] = temp;

    heap = realloc(heap, heapSize*sizeof(Dragon));
    if (!heap) printf("ERROR\n");
    heapSize = heapSize - 1;

    int i = 1;
    while (i*2 <= (heapSize))
    {
        if ((i*2 + 1) <= heapSize)
        {
            if ((double)heap[i].days/heap[i].fine > (double)heap[i*2].days/heap[i*2].fine || (double)heap[i].days/heap[i].fine > (double)heap[i*2 + 1].days/heap[i*2 + 1].fine)
            {
                if ((double)heap[i*2].days/heap[i*2].fine < (double)heap[i*2 + 1].days/heap[i*2 + 1].fine)
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
            if ((double)heap[i].days/heap[i].fine > (double)heap[i*2].days/heap[i*2].fine)
                swap(heap, i, (i*2));
            else
                return heap;
    }

    return heap;
}

int main ()
{
    Dragon* heap = create_minHeap();
    int T, F;
    unsigned long long int dayFine = 0;
    unsigned long long int totalFine = 0;
    int heapSize = 0;
    int i = 1;
    Dragon treinando;
    treinando.days = -1;
    treinando.fine = -1;
    while (scanf("%d %d", &T, &F) != EOF)
    {
        if (treinando.days == -1)
        {
            treinando =  make_dragon(T, F);
        }
        else
        {
            heap = minHeap_insert (heap, heapSize, make_dragon(T, F));
            heapSize++;
        }

        // printf ("   DIA %d:\n", i);
        // printf("TREINANDO = %d %d\n", treinando.days, treinando.fine);
        // for (int j = 1; j <= heapSize; j++)
        // {
        //     printf("%d %d\n", heap[j].days, heap[j].fine);
        // }                
        // printf("dayFine = %d\n", dayFine);
        // printf("totalFine = %d\n\n", totalFine);
        // i++;

        if (heapSize > 0)
            dayFine += F;

        if (treinando.days == 0)
        {
            treinando = heap[1];
            heap = minHeap_delete (heap, heapSize);
            heapSize--;
            dayFine -= treinando.fine;
        }
        treinando.days--;

        totalFine += dayFine;
    }

    while (heapSize > 0)
    {
        // printf ("   DIA %d:\n", i);
        // printf("TREINANDO = %d %d\n", treinando.days, treinando.fine);
        // for (int i = 1; i <= heapSize; i++)
        // {
        //     printf("%d %d\n", heap[i].days, heap[i].fine);
        // }                
        // printf("dayFine = %d\n", dayFine);
        // printf("totalFine = %d\n\n", totalFine);
        totalFine += (treinando.days)*dayFine;
        treinando = heap[1];
        dayFine -= (heap[1].fine);
        heap = minHeap_delete (heap, heapSize);
        heapSize--;
    }
    printf("%llu\n", totalFine);

    return 0;
}
