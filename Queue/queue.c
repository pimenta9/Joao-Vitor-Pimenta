/**
 * @brief Pushes an element to the end of the queue
 * 
 * @param queue pointer to the queue
 * @param num element
 */
Queue* queue_push(Queue *queue, int num)
{  
    Queue* new = (Queue*) malloc(sizeof(Queue));
    if (new)
    {
        new->data = num;
        new->next = NULL;

        if (queue == NULL)
        {
            return new;
        }
        else
        {
            Queue* aux = queue;
            while (aux->next != NULL)
                aux = aux->next;
            aux->next = new;
            return queue;
        }
    }
    else
    {
        printf("ERROR");
    }
}

Queue* queue_pop(Queue *queue)
{
        Queue* aux = queue->next;
        free(queue);
        return aux;
}
