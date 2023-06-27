#include <stdio.h>

int find (int parent[], int x)
{
    if (parent[x] < 0) return x;
    else
        return parent[x] = find(parent, parent[x]);
}

void Union (int parent[], int x, int y)
{
    x = find(parent, x);
    y = find(parent, y);

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

int main ()
{
    int n, m , player_score, q, a, b, sum = 0;
    
    scanf ("%d%d", &n, &m);

    while (m != 0 || n != 0)
    {
        int players[n+1];
        for (int i = 1; i <= n; i++)
        {
            scanf ("%d", &player_score);
            players[i] = -player_score;
        }
        for (int i = 0; i < m; i++)
        {
            scanf ("%d%d%d", &q, &a, &b);
            if (q == 1)
            {
                Union (players, a, b);
            }
            else if (q == 2)
            {
                if (find(players, 1) == find(players, a))
                {
                    if (-players[find(players, 1)] > -players[find(players, b)])
                        sum++;
                }
                else if (find(players, 1) == find(players, b))
                {
                    if (-players[find(players, 1)] > -players[find(players, a)])
                        sum++;
                }
            }
        }
        printf ("%d\n", sum);
        sum = 0;
        scanf ("%d%d", &n, &m);
    }

    return 0;
}
