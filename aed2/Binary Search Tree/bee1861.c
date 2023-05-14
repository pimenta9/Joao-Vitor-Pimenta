#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char name[11];
    int kills;
    struct node *right;
    struct node *left;
} Node;

int string_compare(char string[11], char string2[11])
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string2[i] == '\0')
            return 1;
        
        if (string[i] < string2[i])
            return -1;
        
        if (string[i] > string2[i])
            return 1;
    }
    if (string2[i] == '\0') return 0;
    else return -1;
}

void tree_insert(Node **node, char person[11], int operation)
{
    int i = 0;
    if ((*node) == NULL)
    {
        (*node) = (Node*) malloc(sizeof(Node));
        while (1)
        {
            ((*node)->name)[i] = person[i];
            if (person[i] == '\0') break;
            i++;
        }
        if (operation == 1) (*node)->kills = 1;
        else (*node)->kills = -1;
        (*node)->right = NULL;
        (*node)->left = NULL;
        return;
    }

    if (string_compare(person, (*node)->name) == 0)
    {
        if (operation == 0) (*node)->kills = -1;
        else
            if ((*node)->kills != -1) (*node)->kills++;
    }
    else if (string_compare(person, (*node)->name) == 1)
        tree_insert(&((*node)->right), person, operation);
    else
        tree_insert(&((*node)->left), person, operation);
}

/*
Print the BST using the in-order traversal.
node -> adress of the pointer to the BST's root
*/
void BST_inorder_print(Node **node)
{
    if((*node) == NULL)
        return;
    else
    {
        BST_inorder_print(&((*node)->left));

        if ((*node)->kills != -1)
        {
        printf("%s", (*node)->name);
        printf(" %d\n", (*node)->kills);
        }

        BST_inorder_print(&((*node)->right));

        return;
    }
}

int main ()
{
    Node *tree = NULL;

    char killer[11], victim[11];

    while (scanf("%s", killer) != EOF)
    {
        scanf("%s", victim);
        tree_insert(&tree, killer, 1);
        tree_insert(&tree, victim, 0);
    }
    printf("HALL OF MURDERERS\n");
    BST_inorder_print(&tree);

    return 0;
}
