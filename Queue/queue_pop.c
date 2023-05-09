void queue_pop(Queue **queue)
{
    Queue *aux = (*queue);

    (*queue) = (*queue)->next;

    free(aux);
}

// THIS FUNCTION NEDDS SOME WORK
