/*
Print the BST using the in-order traversal.
node -> adress of the pointer to the BST's root
*/
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
