#include <stdio.h>

int find (int x, int parent[])
{
    if (parent[x] < 0) return x;
    else
        return parent[x] = find(parent[x], parent);
}

void Union (int parent[], int x, int y)
{
    x = find(x, parent);
    y = find(y, parent);

    if (parent[y] < parent[x])
    {
        parent[y] += parent[x];
        parent[x] = y;
    }
    else
    {
        parent[x] += parent[y];
        parent[y] = x;
    }
}

void build (int parent[], int n)
{
    for (int i = 0; i <= n; i++) parent[i] = -1;
}

int main ()
{
    int n, k;
    scanf ("%d%d%*c", &n, &k);

    int Parent[n+1];

    build (Parent, n);
    // for (int i = 0; i <= n; i++)  Parent[i] = -1;

    char op;
    int x, y;
    while (k--)
    {
        scanf ("%c%d%d%*c", &op, &x, &y);
        // printf ("%c %d %d\n", op, x, y);

        if (op == 'C')
        {
            if (find(x, Parent) == find(y, Parent)) printf ("S\n");
            else printf ("N\n");
        }
        else
        {
            Union (Parent, x, y);
        }
    }

    return 0;
}
