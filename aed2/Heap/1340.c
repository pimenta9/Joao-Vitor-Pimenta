#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue* next;
} Queue;

typedef struct stack
{
    int data;
    struct stack* next;
} Stack;

/**
 * @brief Pushes an element to the end of the queue
 * 
 * @param queue pointer to the queue
 * @param num element
 */
Queue* queue_push(Queue *queue, int num)
{  
    Queue* new = (Queue*) malloc(sizeof(Queue));
    if (new)
    {
        new->data = num;
        new->next = NULL;

        if (queue == NULL)
        {
            return new;
        }
        else
        {
            Queue* aux = queue;
            while (aux->next != NULL)
                aux = aux->next;
            aux->next = new;
            return queue;
        }
    }
    else
    {
        printf("ERROR");
    }
}

Queue* queue_pop(Queue *queue)
{
        Queue* aux = queue->next;
        free(queue);
        return aux;
}

Stack* stack_push(Stack* stack, int x)
{
    Stack* new = malloc(sizeof(Stack));
    if (new)
    {
        new->data = x;
        new->next = stack;
        return new;
    }
    else
        printf("ERROR");
}

Stack* stack_pop(Stack* stack)
{
    Stack* aux = stack->next;
    free(stack);
    return aux;
}

int* create_maxHeap()
{
    int* heap = (int*) malloc(sizeof(int));
    if (heap == NULL) printf("ERROR!");
    heap[0] = -1;

    return heap;
}

void swap(int* heap, int i, int j)
{
    heap[i] = heap[i] + heap[j];
    heap[j] = heap[i] - heap[j];
    heap[i] = heap[i] - heap[j];
}

int* maxHeap_insert(int* heap, int heapSize, int x)
{
    heap = (int*) realloc(heap, (heapSize+2)*sizeof(int));

    heap[heapSize + 1] = x;

    int i = heapSize + 1;

    while (i > 1)
    {
        if (heap[i] > heap[i/2])
        {
            swap(heap, i, (i/2));
            i = i/2;
        }
        else
            return heap;
    }
    return heap;
}

int* maxHeap_delete(int* heap, int heapSize)
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
            if (heap[i] < heap[i*2] || heap[i] < heap[i*2 + 1])
            {
                if (heap[i*2] > heap[i*2 + 1])
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
            if (heap[i] < heap[i*2])
                swap(heap, i, (i*2));
            else
                return heap;
    }

    return heap;
}

int main()
{
    int n, operation, x;
    while (scanf("%d", &n) != EOF)
    {
        Queue* queue = NULL;
        Stack* stack = NULL;
        int* heap = create_maxHeap();
        int heapSize = 0;
        int total_deletes = 0;
        int queue_matches = 0;
        int stack_matches = 0;
        int heap_matches = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &operation);
            scanf("%d", &x);
            if (operation == 1)
            {
                queue = queue_push(queue, x);
                stack = stack_push(stack, x);
                heap = maxHeap_insert(heap, heapSize, x);
                heapSize++;
            }
            if (operation == 2)
            {
                if (queue->data == x)
                    queue_matches++;
                queue = queue_pop(queue);
                if (stack->data == x)
                    stack_matches++;
                stack = stack_pop(stack);
                if (heap[1] == x)
                    heap_matches++;
                heap = maxHeap_delete(heap, heapSize);
                heapSize--;
                total_deletes++;
            }
        }
        if (stack_matches == total_deletes)
            stack_matches = 1;
        else stack_matches = 0;

        if (queue_matches == total_deletes)
            queue_matches = 1;
        else queue_matches = 0;

        if (heap_matches == total_deletes)
            heap_matches = 1;
        else heap_matches = 0;

        if (queue_matches || stack_matches || heap_matches)
        {
            if (queue_matches)
            {
                if (stack_matches || heap_matches)
                    printf("not sure\n");
                else
                    printf("queue\n");
            }
            else if (stack_matches)
            {
                if (queue_matches || heap_matches)
                    printf("not sure\n");
                else
                    printf("stack\n");
            }
            else
            {
                if (queue_matches || stack_matches)
                    printf("not sure\n");
                else
                    printf("priority queue\n");
            }
        }
        else
            printf("impossible\n");
    }

    return 0;
}
