#include <stdio.h>
#include <stdlib.h>

#define true 1

typedef struct dragons
{
    int days;
    int fine;
} Dragons;

Dragons* create_maxHeap()
{
    Dragons* heap = (Dragons*) malloc(sizeof(Dragons));
    if (heap == NULL) printf("ERROR!");
    heap[0].days = -1;
    heap[0].fine = -1;

    return heap;
}

void swap(Dragons* heap, int i, int j)
{
    Dragons temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

Dragons* maxHeap_insert(Dragons* heap, int heapSize, Dragons x, int currentFine)
{
    heap = (Dragons*) realloc(heap, (heapSize+1)*sizeof(int));

    heap[heapSize] = x;

    int i = heapSize;

    while (i > 1)
    {
        if (heap[i].days*currentFine < heap[i/2].days*(currentFine - heap[i/2].fine + heap[i].fine))
        {
            swap(heap, i, (i/2));
            i = i/2;
        }
        else
            return heap;
    }
    return heap;
}

Dragons* add_dragon(Dragons* heap, int heapSize, Dragons dragon, int currentFine)
{
    // primeiro dragão
    if (heap[0].days == -1)
    {
        heap[0] = dragon;

        return heap;
    }
    
    return maxHeap_insert(heap, heapSize, dragon, currentFine);
}

Dragons* deleteDragon(Dragons* heap, int heapSize, int currentFine)
{
    Dragons temp = heap[1];
    heap[1] = heap[heapSize-1];
    heap[heapSize-1] = temp;

    heap = (Dragons*) realloc(heap, (heapSize-1)*sizeof(Dragons));
    heapSize--;

    int i = 1;
    while (i*2 <= (heapSize-1))
    {
        if ((i*2 + 1) <= heapSize-1)
        {
            if (heap[i].days*(currentFine-heap[i].fine) > heap[i*2].days*(currentFine - heap[i*2].fine)
             || heap[i].days*(currentFine-heap[i].fine) > heap[i*2+1].days*(currentFine - heap[i*2+1].fine))
            {
                if (heap[i*2].days*(currentFine - heap[i*2].fine) < heap[i*2+1].days*(currentFine - heap[i*2+1].fine))
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
            if (heap[i].days*(currentFine-heap[i].fine) > heap[i*2].days*(currentFine - heap[i*2].fine))
                swap(heap, i, (i*2));
            else
                return heap;
    }
    return heap;
}

int main ()
{
    Dragons* dragons = NULL;
    Dragons x;
    int n = 0;

    // creating the array with all the dragons
    while (scanf("%d%d", &x.days, &x.fine) != EOF)
    {
        n++;
        dragons = realloc (dragons, n*sizeof(Dragons));
        dragons[n-1].days = x.days;
        dragons[n-1].fine = x.fine;
    }

    Dragons* heap = create_maxHeap();
    int totalFine = 0;
    int heapSize = 0;
    int currentFine = 0;

    for (int i = 0; true; i++)
    {
        // if there are still dragons to be added
        if (i < n)
        {
            heap = add_dragon(heap, heapSize, dragons[i], currentFine);
            currentFine += dragons[i].fine;
            if (i)
                heapSize++;
        }

        heap[0].days--;

        // se não tiver nenhum dragão pagando multa
        // e não for o primeiro dia, a contagem acaba
        if (heapSize == 1)
        {
            if (i)
                break;
        }
        // caso contrário adiciona o valor da multa
        // de todos os dragões que não estão sendo treinados
        else
            totalFine += currentFine;

        if (heap[0].days == 0)
        {
            heap = deleteDragon(heap, heapSize, currentFine);
            currentFine -= heap[1].fine;
            heapSize--;
        }
        if (heap == NULL)
            break;
    }
    printf("%d\n", totalFine);

    return 0;
}
