Stack* stack_push(Stack* stack, int x)
{
    Stack* new = malloc(sizeof(Stack));
    if (new)
    {
        new->data = x;
        new->next = stack;
        return new;
    }
    else
        printf("ERROR");
}

Stack* stack_pop(Stack* stack)
{
    Stack* aux = stack->next;
    free(stack);
    return aux;
}
