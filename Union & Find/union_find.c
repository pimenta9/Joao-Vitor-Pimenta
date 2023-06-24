/**
 * @brief find the root of the subset x belongs to
 * 
 * @param x 
 * @param parent 
 * @return int 
 */
int find (int x, int parent[])
{
    // if parent[x] is a value less than zero,
    // x is parent of itself
    if (parent[x] < 0) return x;
    else
        return parent[x] = find(parent[x], parent);
}

/**
 * @brief merge the two subsets which contain x and y;
 * the subset with the greater amount of elements becomes
 * "the parent" of the other one
 * 
 * @param parent 
 * @param x 
 * @param y 
 */
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

/**
 * @brief initializes the array with -1,
 * meaning every element points to itself
 * 
 * @param parent 
 * @param n 
 */
void build (int parent[], int n)
{
    for (int i = 0; i <= n; i++) parent[i] = -1;
}
