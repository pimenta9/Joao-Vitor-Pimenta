void my_selection_sort(int vetor[], int size){

    int indice_menor;
    int menor;

    int i, j;
    for (i = 0; i < size-1; i++)
    {
        menor = vetor[i];
        indice_menor = i;
        for (j = i+1; j < size; j++)
        {
            if(vetor[j] < menor)
            {
                menor = vetor[j];
                indice_menor = j;
            }
        }
        vetor[indice_menor] = vetor[i];
        vetor[i] = menor;
    }
}
