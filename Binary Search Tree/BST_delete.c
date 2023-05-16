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

void BST_insert(Root** root, int number);

void BST_preorder_print(Root** node);

void BST_inorder_print(Root** node);

void BST_postorder_print(Root** node);

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

/**
 * @brief deletes the node with value 'num' from the BST.
 * if the node to be deleted has two children, the greatest
 * value on its left subtree occupies its place
 * 
 * @param root pointer to the root of a non-empty BST
 * @param num value to be deleted
 * @return Root*
 */
Root* BST_delete(Root *root, int num)
{
    // temporary pointer
    Root *temp = NULL;
    // greatest value on left subtree (used for case 3)
    int greatest;

    // if the number we want is less than the current
    // node's data, we move on to the left subtree
    if (num < root->data)
        root->left = BST_delete(root->left, num);

    // if the number we want is greater than the current
    // node's data, we move on to the right subtree
    else if (num > root->data)
        root->right = BST_delete(root->right, num);

    // if we get to the node we want to delete we check if
    // it is a leaf (case 1), if it has only right or left child (case 2)
    // or if it has two children (case 3)
    else
    {
        // case 1
        if (root->right == NULL && root->left == NULL)
        {
            free(root);
            return NULL;
        }
        // case 2 (only left child)
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        // case 2 (only right child)
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        // case 3
        // we clone the greatest value on the left subtree
        // to the current node and delete the node that was cloned
        else
        {
            temp = root->left;
            greatest = temp->data;
            temp = temp->right;

            while (temp != NULL)
            {
                if (temp->data > greatest)
                    greatest = temp->data;
            }

            root->data = greatest;
            BST_delete(root->left, greatest);

            return root;
        }
    }
}

int greatest(Root *node)
{

}

int main()
{    
    // Create the BST
    Root* root = NULL;

    int n;
    // Number of nodes
    scanf("%d", &n);

    int number;
    // Read and insert the n nodes
    while (n > 0)
    {
        scanf("%d", &number);

        BST_insert(&root, number);

        n--;
    }

    BST_levelorder_print(root);
        
    printf("\n");

    int value_deleted;
    printf("value to be deleted: ");
    scanf("%d", &value_deleted);

    BST_delete(root, value_deleted);

    printf("\n\n");
    BST_levelorder_print(root);

    // BST_free(root);

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

void BST_preorder_print(Root** node)
{
    if((*node) == NULL)
        return;
    else
    {
        printf(" %d", (*node)->data);

        BST_preorder_print(&((*node)->left));

        BST_preorder_print(&((*node)->right));

        return;
    }
}

void BST_inorder_print(Root** node)
{
    if((*node) == NULL)
        return;
    else
    {
        BST_inorder_print(&((*node)->left));
        
        printf(" %d", (*node)->data);

        BST_inorder_print(&((*node)->right));

        return;
    }
}

void BST_postorder_print(Root** node)
