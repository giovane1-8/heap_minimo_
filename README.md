<h1>
  Heap de minimo com desativação de índices
</h1>
<p>Para ordenar uma lista como um heap de minimo temos um custo de O(Log N)</p>
<p>Fiz essa adaptação para ser usada em meu projeto de TDE do segundo semestre de ciencia da computação onde faz parte do replacement selection sort um metodo de ordenação feito na decada de 50, onde não tinha muito espaço na memoria primaria dos computadores (RAM) para seber mais <a href="https://stackoverflow.com/questions/16326689/replacement-selection-sort-v-selection-sort" > click aqui</a></p>
<p>Essa adaptação de um heap de minimo para ordenar uma lista inteira tem o custo de O(N * Log N) e não é recursivo como o mergesort ou o quicksort, a vantagem dessa adaptação é que podemos desativar um indice assim ele não sera ordenado em qualquer iteração</p>
