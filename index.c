#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
criamos o tipo vetor que é uma
struct com dois membros,
um guarda o valor o outro se o
item esta ativado ou desativado
*/
typedef struct
{
    // Guarda os caracteres que serão organizados
    char VALUE[50];

    // Guarda se o indece esta ativo
    int ativado;
} vetor;

char last_save_heap[100] = "aaaaaaaaaaaaaaa"; // salva o valor da primeira casa do heap

/*
Parametros:
    1 - vetor que será organizado
    2 - Tamanho do vetor
*/
void make_heap(vetor *, int);

int main()
{
    /*
    srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
    com o valor da função time(NULL). Este por sua vez, é calculado
    como sendo o total de segundos passados desde 1 de janeiro de 1970
    até a data atual.
    Desta forma, a cada execução o valor da "semente" será diferente.
    */
    srand(time(NULL));
    // Guarda o tamanho do heap
    int tamanho_heap = 10000;
    // criamos um vetor do tipo vetor
    vetor vet[tamanho_heap];

    // percorre todo o vetor para inserir os valores aleatoriamente
    for (int i = 0; i < tamanho_heap; i++)
    {
        // insere o valor no item I do vetor no membro VALUE, passando a mascara de 3 caracteres e 3 valores gerados aleatorios da tabela ASCII

        sprintf(vet[i].VALUE, "%c%c%c", (char)((rand() % 25) + 97), (char)((rand() % 25) + 97), (char)((rand() % 25) + 97));
        // Define o item como ativo
        vet[i].ativado = 1;
    }
    // chama a funcao para organizar o vetor
    make_heap(vet, tamanho_heap);

    for (int i = 0; i < tamanho_heap; i++)
    {
        printf("%s, %d\n", vet[i].VALUE, vet[i].ativado);
    }

    return 0;
}

// funcao organiza o vetor passado como parametro em um heap de minimo
void make_heap(vetor *heap, int tamanho_heap)
{
    int indice_pai = tamanho_heap >> 1;        // guarda o valor do ultimo indece que tem um filho
    int i;                                     // variavel auxiliar, recebe em alguns momentos o valor do ultimo indice com filho e o valor de um filho
    int filho;                                 // recebe o valor do indice do filho do nó que esta sendo organizado
    int ultimo_indice_heap = tamanho_heap - 1; // recebe o último índice
    vetor x;                                   // variavel do tipo VETOR auxiliar

    /*
    essa parte do codigo será util se o você quiser organizar uma base de dados com um metodo de organização especifico, como o replacement selection sort
    link para um artigo explicando o replacement selection sort: https://stackoverflow.com/questions/16326689/replacement-selection-sort-v-selection-sort

    // verifica se o indice 0 é menor que last_save_heap, se for verdade, será desativado esse indice para nao ser considerado o menor
    if (0 < strcasecmp(last_save_heap, heap[0].VALUE))
    {
        heap[0].ativado = 0;
    }

    */

    // While continuará até que indice_pai seja menor que 0
    while (indice_pai > 0)
    {
        // de inicio diminuimos já diminuimos 1 porque como trabalhamos com indices o vetor começa do 0; ex: tamanho: 15, 0-14
        indice_pai--;

        i = indice_pai; // guardamos o indice do pai

        filho = 2 * indice_pai + 1; // guardamos o valor em FILHO do filho esquerdo no nosso nó atual

        x = heap[indice_pai]; // compiamos todos os valores do nosso pai

        // verifica qual é maior, o filho esquerdo ou o direito para salvar o valor no menor, verificar tambem se o filho direito esta ativado
        if (filho < ultimo_indice_heap && (0 > strcmp(heap[filho + 1].VALUE, heap[filho].VALUE) || heap[filho].ativado == 0) && heap[filho + 1].ativado == 1)
        {
            filho++;
        }

        // entra no while se o pai é maior que o filho selecionado, ou se o pai esta desativado para afunda-lo
        while (filho <= ultimo_indice_heap && ((0 > strcmp(heap[filho].VALUE, x.VALUE) && heap[filho].ativado == 1) || x.ativado == 0))
        {
            // coloca o valor do filho selecionado no lugar do pai
            heap[i] = heap[filho];

            // i recebe o valor do indice que foi trocado para se o while continuar, pegaremos o filho do nosso filho nessa instancia
            i = filho;

            // pega o valor do filho esquerdo do filho que foi trocado
            filho = 2 * filho + 1;

            // NOVAMENTE. Verifica qual é maior, o filho esquerdo ou o direito para salvar o valor no menor, verificar tambem se o filho direito esta ativado
            if (filho < ultimo_indice_heap && (0 > strcmp(heap[filho + 1].VALUE, heap[filho].VALUE) || heap[filho].ativado == 0) && heap[filho + 1].ativado == 1)
                filho++;
        }

        // pegamos o indice salvo em I que é até onde o nosso pai foi afundado e colocamos no o pai nesse indice
        heap[i] = x;
    }
    /*
        essa parte do codigo é somente necessaria se for organizar alguma base de dados maior que o tamanho do nosso heap assim como a primeiraverificação na funcao

        // verifica se o indice 0 esta desativado, apos rodar o heap, se somente se todos os indices estiverem desativados o primeiro indice vai ficar desativado
        if (heap[0].ativado == 0)
        {
            // reativamos todos os indices
            for (i = 0; i < tamanho_heap; i++)
            {
                heap[i].ativado = 1;
            }

            // reiniciamos a veriavel que salva o valor do indice 0 a cada chamada da funcao
            strcpy(last_save_heap, "aaaaaaaaaaaaaaa");

            //chamamos a funcao novamente para organizar os novos valores
            make_heap(heap, tamanho_heap);
        }
        // copiamos o valor do primeiro indice para na proxima vez que rodarmos a funcao ele fazer a comparação de incio
        strcpy(last_save_heap, heap[0].VALUE);
    */
}