#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Celula *ApontadorCelula;

typedef struct Celula
{
    unsigned int chave;
    unsigned int dado;
    ApontadorCelula prox;
} Celula;

int LLSEinserirInicio(ApontadorCelula *p, Celula celula);

int LLSEcriarListaVazia(ApontadorCelula *p)
{
    (*p) = NULL;

    return (1); // 1 = deu certo
}
int LLSEcriarListaChave(ApontadorCelula *p, Celula celula)
{
    int status_op;

    (*p) = NULL;
    status_op = LLSEinserirInicio(p, celula);

    return status_op;
}
int LLSEinserirInicio(ApontadorCelula *p, Celula celula)
{
    ApontadorCelula q;

    q = (ApontadorCelula)malloc(sizeof(Celula));
    if (q == NULL)
    {
        return -1; // -1 = falha
    }
    else
    {
        q->chave = celula.chave;
        q->dado = celula.dado;
        q->prox = (ApontadorCelula)(*p);
        (*p) = q;
        return (1);
    }
}
int LLSEinserirFinal(ApontadorCelula *p, Celula celula)
{
    ApontadorCelula q, r;

    if ((*p) == NULL)
    {
        return (LLSEinserirInicio(p, celula));
    }
    else
    {
        q = (Celula *)malloc(sizeof(Celula));

        if (q == NULL)
            return -1;
        else
        {
            q->chave = celula.chave;
            q->dado = celula.dado;
            q->prox = (ApontadorCelula)NULL;
            r = (*p);
            while (r->prox != NULL)
            {
                r = r->prox;
            }
            r->prox = q;
            return 1;
        }
    }
}
int LLSEremoverInicio(ApontadorCelula *p)
{
    ApontadorCelula aux;

    if ((*p) == NULL)
        return -1;
    else
    {
        aux = (*p);
        (*p) = (*p)->prox;
        free(aux);

        return 1;
    }
}
int LLSEremoverFinal(ApontadorCelula *p)
{
    ApontadorCelula aux, novo;

    if ((*p) == NULL)
        return -1;
    else
    {
        aux = (*p);
        novo = (*p);

        if ((aux->prox) == NULL)
            return LLSEremoverInicio(p);
        else
        {
            while ((aux->prox) != NULL)
            {
                novo = aux;
                aux = aux->prox;
            }
            novo->prox = NULL;
            free(aux);
            return 1;
        }
    }
}
int LLSEtamanhoLista(ApontadorCelula p)
{
    ApontadorCelula r;
    int tamanho;
    tamanho = 0;

    if (p == NULL)
        return (0);
    else
    {
        tamanho = 1;
        r = p;
        while (r->prox != NULL)
        {
            tamanho++;
            r = r->prox;
        }
        return (tamanho);
    }
}

void imprime(ApontadorCelula p)
{
    ApontadorCelula aux;
    printf("\nA lista : ");
    for (aux = p; aux != NULL; aux = aux->prox)
        printf("%d\t", aux->dado);
    printf("\n\n");
}

void opcao(ApontadorCelula lista)
{
    int op = 1;

    while (op != 0)
    {

        printf("Digite entre as opções abaixo qual operação voce deseja: \n");
        printf("Digite 0 para sair\n");
        printf("Digite 1 para inserir o inicio dessa lista\n");
        printf("Digite 2 para inserir o final dessa lista\n");
        printf("Digite 3 para remover o inicio dessa lista\n");
        printf("Digite 4 para remover o final dessa lista\n");
        printf("Digite 5 para saber o tamanho da lista\n");
        printf("Digite 6 para mostar a lista\n");
        scanf("%d", &op);

        ApontadorCelula aux;
        Celula celula;
        switch (op)
        {
        case 0:
            break;
        case 1:
            printf("Dado:   ");
            scanf("%u", &celula.dado);
            LLSEinserirInicio(&lista, celula);
            break;
        case 2:
            printf("Dado:   ");
            scanf("%u", &celula.dado);
            LLSEinserirFinal(&lista, celula);
            break;

        case 3:
            LLSEremoverInicio(&lista);
            break;
        case 4:
            LLSEremoverFinal(&lista);
            break;
        case 5:
            printf("Tamanho da lista = %d\n\n", LLSEtamanhoLista(lista));
            break;
        case 6:
            imprime(lista);
            break;
        default:
            printf("Comando invalido\n\n");
        }
    }
}

// Função Principal
int main()
{
    ApontadorCelula lista = malloc(sizeof(ApontadorCelula));
    if (!lista)
    {
        printf("Sem memoria disponivel!\n");
        return 0;
    }
    else
    {
        LLSEcriarListaVazia(&lista);
        opcao(lista);

        free(lista);
        return 0;
    }
}
