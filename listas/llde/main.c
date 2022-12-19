#include <stdio.h>
#include <stdlib.h>
#include "llde.h"

int main()
{
    // Lista prinicipal
    CELULA *lista = NULL;

    // Nó descritor
    NoDescritor *no_descritor = (NoDescritor *)malloc(sizeof(NoDescritor));
    no_descritor->tamanho = 0;
    no_descritor->primeira = lista;
    no_descritor->ultima = lista;

    int opcao;
    int valor;
    int chave;

    while(1)
    {
        printf("\n============ MENU ============\n"
            "-> Escolha uma das opções abaixo:\n"
            "   1 - Inserir no início da lista\n"
            "   2 - Inserir no fim da lista\n"
            "   3 - Inserir em ordem por chave\n"
            "   4 - Remover do início da lista\n"
            "   5 - Remover do fim da lista\n"
            "   6 - Remover a célula com uma certa chave da lista\n"
            "   7 - Mostrar o tamanho da lista\n"
            "   8 - Mostrar os elementos da lista\n"
            "   0 - Encerrar o programa\n\n");

        printf("OPÇÃO: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            printf("\n Digite o valor a ser inserido no início da lista: ");
            scanf("%d", &valor);
            inserir_no_inicio(valor, &lista, no_descritor);
            printf(" O valor %d foi inserido no início da lista.\n", valor);
            break;
        }

        /*
        case 2:
            {
            printf("\n Digite o valor a ser inserido no final da lista: ");
            scanf("%d", &valor);
            inserir_no_final(valor, lista, no_descritor);
            break;
            }

        case 3:
            {
            printf("\n Digite o valor a ser inserido e a chave: ");
            printf("\nVALOR: ");
            scanf("%d", &valor);
            printf("\nCHAVE: ");
            scanf("%d", &chave);
            inserir_por_chave(valor, chave, lista, no_descritor);
            break;
            }

        case 4:
            {
            remover_do_inicio(lista, no_descritor);
            }

        case 5:
            {
            remover_do_fim(lista, no_descritor);
            }

        case 6:
            {
            printf("\nCHAVE a ser removida: ");
            scanf("%d", &chave);
            remover_por_chave(chave, lista, no_descritor);
            }

        case 7:
            {
            printf("\n TAMANHO da lista = %d\n", no_descritor->tamanho);
            }
        */
        case 8:
        {
            printf("\n ELEMENTOS da lista: \n");
            mostra_lista(&lista);
            break;
        }

        case 0:
        {
            printf("\n  Até a próxima :)\n\n");
            return 0;
        }

        default:
        {
            printf("\n  Por favor, digite uma opção válida.\n");
            break;
        }
        }
    }
}
