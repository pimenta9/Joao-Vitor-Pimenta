#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;

    struct Node* next;

} node;

typedef struct adjList
{
    node* head;

} AdjList;

typedef struct Graph
{
    // number of vertices
    int v;

    // array of adjacency list
    AdjList* array;

} graph;

graph* graph_build (int n)
{
    graph* g = malloc (sizeof(graph));

    g->v = n;
    g->array = malloc (n * sizeof(AdjList));

    for (int i = 0; i < n; i++)
    {
        g->array[i].head = NULL;
    }

    return g;
}

AdjList list_push (AdjList list, int v)
{
    node* new = malloc (sizeof(node));
    new->vertex = v;
    new->next = list.head;

    list.head = new;

    return list;
}

void print_graph (graph* g)
{
    node* aux;

    for (int i = 0; i < g->v; i++)
    {
        printf ("%d: ", i);
        
        aux = g->array[i].head;

        while (aux != NULL)
        {
            printf ("%d -> ", aux->vertex);
            aux = aux->next;
        }
        printf ("//\n");
    }
}

int main ()
{
    int n = 5;

    graph* g = graph_build (n);

    g->array[1] = list_push (g->array[1], 4);
    g->array[0] = list_push (g->array[0], 2);
    g->array[2] = list_push (g->array[2], 0);
    g->array[3] = list_push (g->array[3], 1);
    g->array[3] = list_push (g->array[3], 2);
    g->array[4] = list_push (g->array[4], 3);

    print_graph (g);

    return 0;
}
