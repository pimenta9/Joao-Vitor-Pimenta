typedef struct Root
{
    int data;
    struct Root *right;
    struct Root *left;

} Root;

/*
Inserts a number to the Binary Search Tree.
root -> the adress of the pointer to the BST's root
number -> the number to be inserted in the BST
*/
void BST_insert(Root** root, int number)
{
    // If we get to an empty node we insert the number, creating that node
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
