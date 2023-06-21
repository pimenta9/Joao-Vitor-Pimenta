#include <stdio.h>
#include <stdlib.h>

typedef struct dragon
{
    int days;
    int fine;
} Dragon;

typedef struct Priority_queue
{
    Dragon dragon;
    struct Priority_queue* next;
} priority_queue;

int main ()
{
    priority_queue* head = NULL;
    int T, F;
    int dayFine = 0;
    int totalFine = 0;
    while (scanf("%d %d", &T, &F) != EOF)
    {
        head = queue_push (head, make_dragon(T, F), dayFine);
        if (head->next != NULL)
            dayFine += F;

        if (head->dragon.days == 0)
        {
            head = queue_pop (head);
            dayFine -= head->dragon.fine;
        }
        else
        {
            head->dragon.days--;
        }
        totalFine += dayFine;
    }

    while (head->next != NULL)
    {
        // code
    }
    printf("%d\n", totalFine);

    return 0;
}
