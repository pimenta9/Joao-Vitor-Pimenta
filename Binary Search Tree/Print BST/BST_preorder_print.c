/*
Print the BST using the pre-order traversal.
node -> the adress of the pointer to the BST's root
*/
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
