#include <stdio.h>
#include <stdlib.h>

#define true 1

typedef struct dragons
{
    int days;
    int fine;
} Dragons;

typedef struct list
{
    Dragons dragon;
    struct list* next;
} List;

int main ()
{
    Dragons* dragons = NULL;
    Dragons x;
    int n = 0;

    // creating the array with all the dragons
    while (scanf("%d%d", &x.days, &x.fine) != EOF)
    {
        n++;
        dragons = realloc (dragons, n*sizeof(Dragons));
        dragons[n-1].days = x.days;
        dragons[n-1].fine = x.fine;
    }

    List* list = NULL;
    int totalFine = 0;

    for (int i = 0; true; i++)
    {
        // if there are still dragons to be added
        if (i < n)
            list = add_dragon(list, dragons[i]);

        (list->dragon).days--;

        // se não tiver nenhum dragão pagando multa
        // e não for o primeiro dia, a contagem acaba
        if (list->next == NULL)
        {
            if (i)
                break;
        }
        // caso contrário adiciona o valor da multa
        // de todos os dragões que não estão sendo treinados
        else
            totalFine += dayFine(list->next);

        if ((list->dragon).days == 0)
            list = deleteDragon(list);
        if (list == NULL)
            break;
    }
    printf("%d\n", totalFine);

    return 0;
}
