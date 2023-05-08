#include <stdio.h>
#include <stdlib.h>

typedef struct Root
{
    int data;
    struct Root *right;
    struct Root *left;

} Root;

typedef struct queue
{
    Root *node;
    struct queue *next;
} Queue;

void BST_insert(Root** root, int number);

/**
 * @brief Print the elements on the Binary Search Tree using
 * level order traversal.
 * @param root pointer to the BST's root (top element).
 */
void BST_levelorder_print(Root *root);

void queue_push(Queue *queue, Root **node);

void queue_pop(Queue **queue);

int main()
{
    int c, n, number;
    scanf("%d", &c);

    while(c > 0)
    {
        Root *root = NULL;

        scanf("%d", &n);

        while(n > 0)
        {
            scanf("%d", &number);

            BST_insert(&root, number);

            n--;
        }

        BST_levelorder_print(root);

        c--;
    }

    return 0;
}

void BST_insert(Root** root, int number)
{
    // If we get to an empty node we insert the number
    if((*root) == NULL)
    {
        (*root) = (Root*) malloc(sizeof(Root));
        (*root)->data = number;
        (*root)->right = NULL;
        (*root)->left = NULL;
    }
    else
    {
        // If the number is greater or equal we insert it on the right part of the tree
        if (number >= ((*root)->data))
        {
            BST_insert(&((*root)->right), number);
        }
        // If it's less we insert it on the left part
        else
        {
            BST_insert(&((*root)->left), number);
        }        
    }
}

void BST_levelorder_print(Root *root)
{
    Queue *head = (Queue *) malloc(sizeof(Queue));

    head->node = root;
    head->next = NULL;

    while (head != NULL)
    {
        printf("%d ", (head->node)->data);

        queue_push(head, &(head->node)->left);
        queue_push(head, &(head->node)->right);

        queue_pop(&head);
    }
}

void queue_push(Queue *queue, Root **node)
{
    if ((*node) == NULL)
        return;    

    Queue *new = (Queue *) malloc(sizeof(Queue));

    Queue *aux;

    if(new == NULL)
        printf("ERROR!");
    else
    {
        new->node = (*node);
        new->next = NULL;

        aux = queue;

        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = new;
    }
}

void queue_pop(Queue **queue)
{
    Queue *aux = (*queue);

    (*queue) = (*queue)->next;

    free(aux);
}
