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
    {
        if (root->left != NULL)
            root->left = BST_delete(root->left, num);
        else
            return root;
    }

    // if the number we want is greater than the current
    // node's data, we move on to the right subtree
    else if (num > root->data)
    {
        if (root->right != NULL)
            root->right = BST_delete(root->right, num);
        else
            return root;
    }

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
            root->left = BST_delete(root->left, greatest);
        }
    }
    return root;
}
