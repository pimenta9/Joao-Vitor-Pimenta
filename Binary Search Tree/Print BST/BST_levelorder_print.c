/**
 * @brief Print the elements on the Binary Search Tree using
 * level order traversal.
 * Needs a queue to be functional.
 * 
 * @param root pointer to the BST's root (top element).
 */
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
