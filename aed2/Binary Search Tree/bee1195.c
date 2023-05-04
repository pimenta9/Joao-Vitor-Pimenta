#include <stdio.h>
#include <stdlib.h>

typedef struct Root
{
    int data;
    struct Root *right;
    struct Root *left;

} Root;

void BST_insert(Root** root, int number);

void BST_preorder_print(Root** node);

void BST_inorder_print(Root** node);

void BST_postorder_print(Root** node);

//void BST_right_print(Root* root); (APENAS UM TESTE!)

int main()
{
    int n, c, number;
    scanf("%d", &c);
    
    int cases = 1;
    while (c > 0)
    {
        // Create the BST
        Root* root = NULL;

        // Number of nodes
        scanf("%d", &n);

        // Read and insert the n nodes
        while (n > 0)
        {
            scanf("%d", &number);

            BST_insert(&root, number);

            n--;
        }

        //BST_right_print(root);

        printf("Case %d:\n", cases);
        printf("Pre.:", BST_preorder_print(&root));
        printf("In..:", BST_inorder_print(&root));
        printf("Post:", BST_postorder_print(&root));

        // BST_free(root);
        cases++;
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

// APENAS UM TESTE! APAGAR!!!!!
void BST_right_print(Root* root)
{
    Root* aux = root;

    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->left;
    }
    printf("\n");
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
