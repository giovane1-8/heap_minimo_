typedef struct
{
    char VALUE[100];
    int ativado;
} base_dados;

char last_save_heap[100] = "aaaaaaaaaaaaaaa"; // salva o ultimo valor retornado pela funcao

// parametros: 1- vetor que é retornado organizado como um heap de minimo 2- o tamanho do vetor
void make_heap(base_dados *, int);

int main()
{

    return 0;
}

// funcao organiza o vetor passado como parametro em um heap de minimo
void make_heap(base_dados *heap, int tamanho_heap)
{
    int ultimo_indice_com_filho = tamanho_heap >> 1, i, indice_filho_ESQUERDO, ultimo_indice_heap = tamanho_heap - 1, teste; // índice do último
    base_dados x;
    // printf("%s %s",last_save_heap,heap[0].VALUE );
    teste = strcasecmp(last_save_heap, heap[0].VALUE);

    if (0 < teste)
    {
        heap[0].ativado = 0;
    }
    while (ultimo_indice_com_filho > 0)
    {

        ultimo_indice_com_filho--;
        i = ultimo_indice_com_filho;

        indice_filho_ESQUERDO = 2 * ultimo_indice_com_filho + 1; // índices do filho ESQUERDO
        x = heap[ultimo_indice_com_filho];                       // novo elemento

        // verifica qual é maior, o filho esquerdo ou o direito para se necessario fazer a troca com o pai, verificar tambem se o filho direito esta ativado
        if (indice_filho_ESQUERDO < ultimo_indice_heap && (0 > strcmp(heap[indice_filho_ESQUERDO + 1].VALUE, heap[indice_filho_ESQUERDO].VALUE) || heap[indice_filho_ESQUERDO].ativado == 0) && heap[indice_filho_ESQUERDO + 1].ativado == 1)
        {
            indice_filho_ESQUERDO++;
        }

        // entra no while se o pai é maior que o filho, esquerdo ou direito, e se o pai esta desativado para afunda-lo
        while (indice_filho_ESQUERDO <= ultimo_indice_heap && ((0 > strcmp(heap[indice_filho_ESQUERDO].VALUE, x.VALUE) && heap[indice_filho_ESQUERDO].ativado == 1) ||
                                                               x.ativado == 0))
        {
            // coloca o valor do filho (esquerdo ou direito) no lugar do pai
            heap[i] = heap[indice_filho_ESQUERDO];

            // salva o indice que foi copiado para colocar o valor salvo em X
            i = indice_filho_ESQUERDO;
            // pega o valor do filho esquerdo do filho
            indice_filho_ESQUERDO = 2 * indice_filho_ESQUERDO + 1;

            // verifica qual é maior, o filho esquerdo ou o direito para se necessario fazer a troca com o pai, verificar tambem se o filho direito esta ativado
            if (indice_filho_ESQUERDO < ultimo_indice_heap && (0 > strcmp(heap[indice_filho_ESQUERDO + 1].VALUE, heap[indice_filho_ESQUERDO].VALUE) || heap[indice_filho_ESQUERDO].ativado == 0) && heap[indice_filho_ESQUERDO + 1].ativado == 1)
                indice_filho_ESQUERDO++;
        }

        // coloca o valor que foi substituido do pai no indice do filho
        heap[i] = x;
    }
    if (heap[0].ativado == 0)
    {
        for (i = 0; i < tamanho_heap; i++)
        {
            heap[i].ativado = 1;
        }
        strcpy(last_save_heap, "aaaaaaaaaaaaaaa");
        make_heap(heap, tamanho_heap);
    }
    strcpy(last_save_heap, heap[0].VALUE);
}