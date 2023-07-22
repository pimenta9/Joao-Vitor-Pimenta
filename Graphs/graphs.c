#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int num_nodes;
    int** edges;
} graph;

graph* graph_build (int n)
{
    graph* g = malloc (sizeof(graph));
    g->num_nodes = n;

    g->edges = malloc (n * sizeof(graph));
    for (int i = 0; i < n; i++)
        g->edges[i] = calloc (n, sizeof(graph));

    return g;
}

graph* add_edge (graph* g, int from, int to)
{
    (g->edges)[from][to] = 1;

    return g;
}

int main ()
{
    graph* g = graph_build (3);
    
    g = add_edge (g, 1, 0);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf ("%d ", g->edges[i][j]);
        }
        printf ("\n");
    }

    return 0;
}
