#include <stdio.h>
#include <stdlib.h>

typedef struct Cashier
{
    int time;
    int id;
} cashier;

typedef struct Priotiry_queue
{
    cashier Cashier;
    struct Priority_queue* next;
} priority_queue;

priority_queue* pq_push (priority_queue* top, cashier x)
{
    if (top == NULL)
    {
        priority_queue* new = malloc (sizeof (priority_queue));
        new->Cashier = x;
        new->next = NULL;
        return new;
    }

    if (x.time < top->Cashier.time)
    {
        priority_queue* new = malloc (sizeof (priority_queue));
        new->Cashier = x;
        new->next = top;
        return new;
    }
    else if (x.time == top->Cashier.time)
    {
        if (x.id < top->Cashier.id)
        {
            priority_queue* new = malloc (sizeof (priority_queue));
            new->Cashier = x;
            new->next = top;
            return new;
        }
        else
        {
            top->next = pq_push (top->next, x);
            return top;
        }
    }
    else
    {
        top->next = pq_push (top->next, x);
        return top;
    }
}

priority_queue* pq_pop (priority_queue* top)
{
    priority_queue* aux = top->next;

    free (top);

    return aux;
}

int greatest (int x, int y)
{
    if (x > y) return x;
    else return y;
}

cashier makeCashier (int a, int b)
{
    cashier x;
    x.time = a;
    x.id = b;
    return x;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    priority_queue* head = NULL;
    
    for (int i = 0; i < n; i++)
        head = pq_push(head, makeCashier (0, i));

    int c;
    int totalTime = 0;
    while (m--)
    {
        scanf("%d", &c);

        // id do caixa que vai atender o cliente c
        // esse caixa é o que estiver livre no momento
        // se mais de um estiver livre, será o caixa de menor id
        int id = head->Cashier.id;
        // x é o tempo em que o caixa 'id' estará livre novamente
        int x = (head->Cashier.time) + v[id]*c;

        head = pq_pop(head);

        head = pq_push(head, makeCashier (x, id));

        // se o caixa que atenderá o cliente c ultrapassar o tempo
        // total, esse tempo total será alterado
        totalTime = greatest (x, totalTime);
    }
    printf("%d\n", totalTime);

    return 0;
}
