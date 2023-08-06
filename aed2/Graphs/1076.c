#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int t, n, v, a, from, to, sum = 0;
    scanf ("%d", &t);

    while (t--)
    {
        scanf ("%d%d%d", &n, &v, &a);

        graph* g = graph_build (v);

        for (int i = 0; i < a; i++)
        {
            scanf ("%d%d", &from, &to);
            add_edge (g, from, to);
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                // printf ("%d ", g->edges[i][j]);
                if (g->edges[i][j] == 1)
                {
                    sum++;
                    g->edges[j][i] = 0;
                }
            }
            // printf("\n");
        }
        
        printf ("%d\n", sum*2);

        sum = 0;
    }
    return 0;
}
