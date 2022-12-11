#include <stdio.h>
#include <stdlib.h>

// TAD - Variaveis globais
typedef struct no No;
typedef struct head Head;

// Estruturas de dados
struct no {
    int data;
    struct no* prox;
};

struct head {
    No* inicio;
};

// Prototipos
No* criaFila(int* data);
void insereElemento(Head* h, int* data);
int removeElemento(Head* h);
void mostraFila(Head* h);

// Programa principal
int main() {
    Head* h = NULL;
    int a;

    h = (Head*) malloc(sizeof(Head));
    h->inicio = NULL;
    a = 10;
    insereElemento(h, &a);
    a = 20;
    insereElemento(h, &a);
    a = 30;
    insereElemento(h, &a);
    a = 40;
    insereElemento(h, &a);
    a = 50;
    insereElemento(h, &a);
    mostraFila(h);
    removeElemento(h);
    mostraFila(h);
    removeElemento(h);
    mostraFila(h);

    return(EXIT_SUCCESS);
}

No* criaFila(int* data) {
    No* no = NULL;
    
    no = (No*) malloc(sizeof(No));
    if(no) {
        no->data = *data;
        no->prox = NULL;
    }

    return no;
}

void insereElemento(Head* h, int* data) {
    No* x = criaFila(data);

    if(h == NULL || x == NULL)
        return;
    if(h->inicio == NULL)
        h->inicio = x;
    else {
        No* a = h->inicio;
        while(a->prox != NULL)
            a = a->prox;

        a->prox = x;
    }
}

int removeElemento(Head* h) 
{
    No *aux = h->inicio;
    
    if(h->inicio == NULL){
        printf("A pilha já está vazia!");
        return 0;
    }
    else
    {
        if(aux->prox == NULL)
        {
            free(aux);
            h->inicio = NULL;
        }
        else
        {
            while((aux->prox)->prox != NULL)
            {
                aux = aux->prox;
            }
            free(aux->prox);
            aux->prox = NULL;
        }
    }
}

void mostraFila(Head* h) 
{
    printf("\n");
    No *aux = h->inicio;
    
    int contador = 1;
    
    while(aux != NULL)
    {
        printf("%dº Nó = %d\n", contador, aux->data);
        contador++;
        aux = aux->prox;
    }
}
