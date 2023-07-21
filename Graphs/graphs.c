#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mygraph
{
    int numnodes;
    bool** edges;
} graph;

graph* create_graph (int numnodes)
{
    graph* g = malloc (sizeof(graph));

    g->numnodes = numnodes;

    g->edges = calloc (sizeof(bool*), g->numnodes);
    for (int i = 0; i < g->numnodes; i++)
        g->edges[i] = calloc (sizeof(bool), g->numnodes);

    return g;
}

void print_graph (graph* g)
{
    printf ("digraph\n{\n");

    for (int from = 0; from < g->numnodes; from++)
    {
        for (int to = 0; to < g->numnodes; to++)
        {
            if (g->edges[from][to])
                printf ("%d -> %d;\n", from, to);
        }
    }
    printf ("}\n");
}

bool has_edge (graph* g, unsigned int from_node, unsigned int to_node)
{
    return (g->edges)[from_node][to_node];
}

bool add_edge (graph* g, unsigned int from_node, unsigned int to_node)
{
    if (has_edge (g, from_node, to_node))
        return false;

    (g->edges)[from_node][to_node] = true;
    return true;
}

int main ()
{
    graph* g1 = create_graph (3);

    print_graph (g1);

    add_edge (g1, 2, 1);

    print_graph (g1);

    return 0;
}
