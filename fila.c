#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int data;
    struct no *proximo;
} No;

void inserir_na_fila(No * *fila, int num)
{
    No *novo = malloc(sizeof(No));
    No *aux;
    
    if(novo != NULL)
    {
        novo->data = num;
        novo->proximo = NULL;
    
        if(*fila == NULL)
        {
            (*fila) = novo;
        }
        else
        {
            aux = (*fila);
            
            while(aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else
    {
        printf("error");
        return;
    }
}

void mostrar_fila(No *fila)
{
    int contador = 1;
    
    No *aux;
    
    aux = fila;
    
    printf("%dº Nó = %d\n", contador, aux->data);
    contador++;
    
    while(aux->proximo != NULL)
    {
        aux = aux->proximo;
        
        printf("%dº Nó = %d\n", contador, aux->data);
        contador++;
    }
    printf("\n");
}

No* remover_da_fila(No *fila)
{
    fila = fila->proximo;
    
    return fila;
}

int main(){
    
    No *fila = NULL;
    
    inserir_na_fila(&fila, 5);
    inserir_na_fila(&fila, 63);
    inserir_na_fila(&fila, 90);
    inserir_na_fila(&fila, 0);
    inserir_na_fila(&fila, -15);
    
    mostrar_fila(fila);
    
    fila = remover_da_fila(fila);
    mostrar_fila(fila);
    
    fila = remover_da_fila(fila);
    mostrar_fila(fila);
    
    fila = remover_da_fila(fila);
    mostrar_fila(fila);
    
    return 0;
}
