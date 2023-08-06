#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int i;
    int j;
    struct Node* next;
} node;

typedef struct Queue
{
    node* head;
    node* tail;
} queue;

queue* enqueue (queue* q, int i, int j)
{
    node* new = malloc (sizeof(node));
    new->i = i;
    new->j = j;
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

queue* dequeue (queue* q)
{
    node* aux = q->head;

    q->head = q->head->next;

    free (aux);

    if (q->head == NULL) q->tail = NULL;

    return q;
}

void print_queue (node* head)
{
    node* aux = head;

    while (aux != NULL)
    {
        printf ("[ %d / %d ] -> ", aux->i, aux->j);
        aux = aux->next;
    }
    printf ("//\n");
}
