#include <stdio.h>

int graph[21][21];
int vis[21];

typedef struct Spam
{
    int p;
    int t1, t2;
    char a1[21], a2[21], a3[21];
} spam;

spam vetor[101];

void add_edge (int from, int to)
{
    graph[from][to] = 1;
}

char nomes[21][21];

char caracteristicas[21][100][21];

void DFS (int p, int n)
{
    vis[p] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (graph[p][i] == 1 && vis[i] == 0)
        {
            DFS (i, n);
        }
    }
}

void add_caracteristica (int i, int j, char str[21])
{
    for (int k = 0; str[k] != '\0'; k++)
    {
        caracteristicas[j][i][k] = str[k];
    }
}

int main ()
{
    int n, F;
    scanf ("%d", &n);

    while (n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            graph[i][0] = 0;
            vis[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            scanf ("%d", &F);
            while (F != 0)
            {
                add_edge (i, F);
                graph[i][0]++;

                scanf ("%d", &F);
            }
        }

        int p, n_spams = 0;
        scanf ("%d", &p);

        while (p != 0)
        {
            vetor[n_spams].p = p;

            scanf("%d", &vetor[n_spams].t1);
            scanf("%d%*c", &vetor[n_spams].t2);

            scanf ("%s", vetor[n_spams].a1);
            scanf ("%s", vetor[n_spams].a2);
            scanf ("%s", vetor[n_spams].a3);

            n_spams++;

            scanf ("%d%*c", &p);
        }

        for (int i = 1; i <= n; i++)
            scanf ("%s", nomes[i]);

        /*  
        // DEBUG

        for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j < 21; j++)
            {
                printf ("%d ", graph[i][j]);
            }
            printf ("\n");
        }
        printf ("\n");

        for (int i = 0; i < n_spams; i++)
        {
            printf ("p = %d\n", vetor[i].p);
            printf ("t1 = %d t2 = %d\n", vetor[i].t1, vetor[i].t2);
            printf ("%s\n", vetor[i].a1);
            printf ("%s\n", vetor[i].a2);
            printf ("%s\n", vetor[i].a3);
        }
        printf ("\n");

        for (int i = 1; i <= n; i++)
            printf ("%s\n", nomes[i]); 

        */

        for (int i = 0; i < n_spams; i++)
        {
            DFS (vetor[i].p, n);

            for (int j = 1; j <= n; j++)
            {
                if (vis[j] == 1)
                {
                    if (graph[j][0] <= vetor[i].t1)
                    {
                        add_caracteristica (i, j, vetor[i].a1);
                    }
                    else if (graph[j][0] < vetor[i].t2)
                    {
                        add_caracteristica (i, j, vetor[i].a2);
                    }
                    else
                    {
                        add_caracteristica (i, j, vetor[i].a3);
                    }
                }
                else
                {
                    add_caracteristica (i, j, vetor[i].a1);
                }
            }

            for (int i = 1; i <= n; i++)
            {
                vis[i] = 0;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            printf ("%s: ", nomes[i]);
            for (int j = 0; j < n_spams; j++)
            {
                printf ("%s ", caracteristicas[i][j]);
            }
            printf ("\n");
        }

        scanf ("%d", &n);
    }

    return 0;
}
