#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int i;
    struct Node* next;
} node;

typedef struct Queue
{
    node* head;
    node* tail;
} queue;

/**
 * @brief insert an element on the end of the queue
 * 
 * @param q pointer to the queue
 * @param i element to be inserted
 * @return pointer to the queue after element has
 * been inserted
 */
queue* enqueue (queue* q, int i)
{
    node* new = malloc (sizeof(node));
    new->i = i;
    new->next = NULL;

    if (q->head == NULL)
    {
        q->head = new;
        q->tail = new;
        return q;
    }

    q->tail->next = new;
    q->tail = new;
    
    return q;
}

/**
 * @brief pops the first element of the queue
 * 
 * @param q pointer to the queue
 * @return pointer to the queue after the element on the top
 * has been popped
 */
queue* dequeue (queue* q)
{
    node* aux = q->head;

    q->head = q->head->next;

    free (aux);

    if (q->head == NULL) q->tail = NULL;

    return q;
}

/**
 * @brief prints the elements of the queue
 * 
 * @param q pointer to the queue
 */
void print_queue (queue* q)
{
    node* aux = q->head;

    while (aux != NULL)
    {
        printf ("[ %d ] -> ", aux->i);
        aux = aux->next;
    }
    printf ("//\n");
}

/**
 * @brief creates a new queue
 * 
 * @return the pointer to the new queue
 */
queue* new_queue ()
{
    queue* new = malloc (sizeof(queue));
    new->head = NULL;
    new->tail = NULL;

    return new;
}

// testing...
int main ()
{
    queue* q = new_queue();

    q = enqueue (q, 2);
    q = enqueue (q, 4);
    q = enqueue (q, 7);
    q = enqueue (q, 1);
    q = enqueue (q, 9);

    print_queue (q);

    q = dequeue (q);
    q = dequeue (q);
    q = dequeue (q);

    print_queue (q);

    return 0;
}
