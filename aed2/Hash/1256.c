#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct Node
{
    int x;
    struct Node* next;
} node;

void hash_build (node* hashTable[], int m)
{
    for (int i = 0; i < m; i++)
        hashTable[i] = NULL;

    return;
}

void hash_push (node* hashTable[], int m, int num)
{
    node* new = malloc (sizeof (node));
    new->x = num;
    new->next = NULL;

    if (hashTable[num%m] == NULL)
    {
        hashTable[num%m] = new;
        return;
    }

    node* aux = hashTable[num%m];
    while (aux->next != NULL)
        aux = aux->next;

    aux->next = new;
    return;
}

void hash_print (node* hashTable[], int m)
{
    node* aux;
    for (int i = 0; i < m; i++)
    {
        printf ("%d -> ", i);
        aux = hashTable[i];
        while (aux != NULL)
        {
            printf ("%d -> ", aux->x);
            aux = aux->next;
        }
        printf ("\\\n");
    }
}

int main ()
{
    int n, m, c, x, first_testCase = true;
    scanf ("%d", &n);

    while (n--)
    {
        if (first_testCase == false)
            printf ("\n");

        scanf("%d%d", &m, &c);

        node* hashTable[m];

        hash_build (hashTable, m);

        while (c--)
        {
            scanf ("%d", &x);
            hash_push (hashTable, m, x);
        }

        hash_print (hashTable, m);

        first_testCase = false;
    }

    return 0;
}
