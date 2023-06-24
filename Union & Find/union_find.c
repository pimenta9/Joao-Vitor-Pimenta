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
