/*
Print the BST using the post-order traversal.
node -> adress of the pointer to the BST's root
*/
void BST_postorder_print(Root** node)
{
    if((*node) == NULL)
        return;
    else
    {
        BST_postorder_print(&((*node)->left));

        BST_postorder_print(&((*node)->right));
        
        printf(" %d", (*node)->data);

        return;
    }
}
