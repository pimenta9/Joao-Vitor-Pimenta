#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    scanf("%d", &n);

    int nodes;

    while (n > 0)
    {
        scanf("%d", &nodes);

        char tree[(int)pow(2, nodes)];
        for(i = 0; i < (int)pow(2, nodes); i++)
            tree[i] = '0';

        char s1[nodes];
        char s2[nodes];

        scanf("%s", s1);
        scanf("%s", s2);

        

        n--;
    }
}
