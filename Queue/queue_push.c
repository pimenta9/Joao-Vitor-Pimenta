/**
 * @brief Pushes an element to the end of the queue
 * 
 * @param queue pointer to the queue
 * @param num element
 */
void queue_push(Queue *queue, int num)
{  
  Queue *new = (Queue *) malloc(sizeof(Queue));

  Queue *aux;

  if(new == NULL)
    printf("ERROR!");
  else
  {
    new->data = num;
    new->next = NULL;

    aux = queue;

    while(aux->next != NULL){
      aux = aux->next;
    }

    aux->next = new;
  }
}

// THIS FUNCTION NEEDS SOME WORK
