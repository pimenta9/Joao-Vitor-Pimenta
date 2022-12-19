#include <stdio.h>
#include <stdlib.h>
#include "llde.h"

void inserir_no_inicio(int valor, CELULA **lista, NoDescritor *nod)
{
    CELULA *novo = (CELULA*)malloc(sizeof(CELULA));
    novo->anterior = NULL;
    novo->chave = 1;
    novo->conteudo = valor;
    //novo->proximo = NULL;

    // Se a lista estiver vazia,
    if ((*lista) == NULL)
    {
        novo->proximo = NULL;
        (*lista) = novo;

        nod->primeira = novo;
        nod->tamanho = 1;
        nod->ultima = novo;
    }
    // Se não estiver vazia,
    else
    {
        novo->proximo = nod->primeira;

        (*lista) = novo;

        // Mudar a chave dos elementos que foram passados a frente
        //organiza_chaves(*lista);
    }
}

void mostra_lista(CELULA **lista)
{
    CELULA *aux = (*lista);

    if ((*lista) == NULL)
        printf("        A lista está vazia.\n");

    else
    {
        printf("        chave 1 = %d\n", aux->conteudo);

        while (aux != NULL)
        {
            if (aux->chave != 1)
                printf("        chave %d = %d\n", aux->chave, aux->conteudo);

            if (aux->proximo != NULL) aux = aux->proximo;
            else aux = NULL;
        }
    }
}
