// Structs
struct celula
{
    struct celula *anterior;

    int chave;

    int conteudo;

    struct celula *proximo;
};
typedef struct celula CELULA;

typedef struct nod
{
    CELULA *primeira;
    int tamanho;
    CELULA *ultima;
} NoDescritor;

// Declaração das funções

/**
 * @brief Insere um elemento com chave 1 no início da lista
 * e organiza as chaves dos elementos já presentes na lista.
 * 
 * @param valor elemento a ser inserido
 * @param lista lista a ser alterada
 * @param nod nó descritor
 */
void inserir_no_inicio(int valor, CELULA **lista, NoDescritor *nod);

/**
 * @brief Mostra os elementos presentes na lista por ordem
 * de chave
 * 
 * @param lista lista a ser mostrada
 */
void mostra_lista(CELULA **lista);
