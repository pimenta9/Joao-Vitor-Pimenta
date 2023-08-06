#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int i;
    int j;
    struct Node* next;
} node;

typedef struct Queue
{
    node* head;
    node* tail;
} queue;

queue* enqueue (queue* q, int i, int j)
{
    node* new = malloc (sizeof(node));
    new->i = i;
    new->j = j;
    new->next = NULL;

    if (q->head == NULL)
    {
        q->head = new;
        q->tail = new;
        return q;
    }

    q->tail->next = new;
    q->tail = new;
    
    return q;
}

queue* dequeue (queue* q)
{
    node* aux = q->head;

    q->head = q->head->next;

    free (aux);

    if (q->head == NULL) q->tail = NULL;

    return q;
}

void print_queue (node* head)
{
    node* aux = head;

    while (aux != NULL)
    {
        printf ("[ %d / %d ] -> ", aux->i, aux->j);
        aux = aux->next;
    }
    printf ("//\n");
}

char** BFS (char** mat, queue* q, int n, int m, int i, int j)
{
    q = enqueue (q, i, j);

    while (q->head != NULL)
    {
        // print_queue (queue);

        i = q->head->i;
        j = q->head->j;

        // if (mat[i][j] != 'x')
        // {
            // esquerda
            if (j-1 >= 0)
            {
                if (mat[i][j-1] == '.')
                {
                    q = enqueue (q, i, j-1);
                    mat[i][j-1] = '*';
                }
            }
            // direita
            if (j+1 < m)
            {
                if (mat[i][j+1] == '.')
                {
                    q = enqueue (q, i, j+1);
                    mat[i][j+1] = '*';
                }
            }
            // cima
            if (i-1 >= 0)
            {
                if (mat[i-1][j] == '.')
                {
                    q = enqueue (q, i-1, j);
                    mat[i-1][j] = '*';
                }
            }
            // baixo
            if (i+1 < n)
            {
                if (mat[i+1][j] == '.')
                {
                    q = enqueue (q, i+1, j);
                    mat[i+1][j] = '*';
                }
            }
        // }

        mat[i][j] = 'x';

        q = dequeue(q);
    }

    return mat;
}

int main ()
{
    int n, m;
    scanf ("%d%d%*c", &n, &m);

    char** matriz = malloc (n * sizeof(char*));
    for (int i = 0; i < n; i++)
        matriz[i] = malloc (m * sizeof(char));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf ("%c", &matriz[i][j]);
        }
        scanf ("%*c");
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         printf ("%c", matriz[i][j]);
    //     }
    //     printf ("\n");
    // }

    int sum = 0;

    queue* q = malloc (sizeof(queue*));
    q->head = NULL;
    q->tail = NULL;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matriz[i][j] == '.')
            {
                sum++;
                matriz = BFS (matriz, q, n, m, i, j);
                // printf ("\n");
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         printf ("%c", matriz[i][j]);
    //     }
    //     printf ("\n");
    // }

    printf ("%d\n", sum);

    return 0;
}
